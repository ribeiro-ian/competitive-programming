#!/usr/bin/env python3
"""
cp-format: clang-format post-processor for competitive programming style.

Fixes two things clang-format can't do:
  1. Keeps `if/for/while (...) single_statement;` on one line (no braces)
  2. Joins `ios_base::sync_with_stdio(...); cin.tie(...);` onto one line

Usage:
  # dry run (print to stdout)
  python3 cp-format.py file.cpp

  # in-place
  python3 cp-format.py -i file.cpp

  # all .cpp in repo (dry run)
  python3 cp-format.py $(find . -name "*.cpp")

  # all .cpp in repo (in-place)
  python3 cp-format.py -i $(find . -name "*.cpp")
"""

import re
import sys
import subprocess
import argparse
from pathlib import Path


# ---------------------------------------------------------------------------
# Transform passes
# ---------------------------------------------------------------------------

_CIN_SINGLE_VAR_RE = re.compile(
    r'^\s*cin\s*>>\s*[A-Za-z_][A-Za-z0-9_]*\s*;\s*$'
)

def join_cin_reads(lines: list[str]) -> list[str]:
    """
    Joins:
        int n;
        cin >> n;

    into:
        int n; cin >> n;

    ONLY when cin reads exactly one plain variable.
    """
    result = []
    i = 0

    while i < len(lines):
        if i + 1 < len(lines):
            a = lines[i].strip()
            b = lines[i + 1].strip()

            if (
                a.endswith(';')
                and _CIN_SINGLE_VAR_RE.match(b)
                and '{' not in a
                and '}' not in a
            ):
                indent = lines[i][:len(lines[i]) - len(lines[i].lstrip())]
                result.append(f"{indent}{a} {b}\n")
                i += 2
                continue

        result.append(lines[i])
        i += 1

    return result

def join_short_control_statements(lines: list[str]) -> list[str]:
    """
    Joins:
        if (cond) {
          stmt;
        }
    into:
        if (cond) { stmt; }

    And also plain (no-brace, clang already put on next line):
        if (cond)
          stmt;
    into:
        if (cond) stmt;

    Works for if / else if / for / while.
    """
    result = []
    i = 0
    CONTROL = re.compile(r'^(\s*)(if\s*\(|else if\s*\(|for\s*\(|while\s*\()')

    while i < len(lines):
        line = lines[i]

        # Case 1: control line ending with `{` on same line
        # Pattern:
        #   if (...) {
        #     stmt;
        #   }
        if CONTROL.match(line) and line.rstrip().endswith('{'):
            indent = len(line) - len(line.lstrip())
            # peek: next non-empty line is a single statement, then closing `}`
            if (i + 2 < len(lines)
                    and lines[i + 2].strip() == '}'
                    and not lines[i + 1].rstrip().endswith('{')):
                stmt = lines[i + 1].strip()
                head = line.rstrip()  # "  if (...) {"
                result.append(f"{head} {stmt} }}\n")
                i += 3
                continue

        # Case 2: control line with no `{`, body on next line (clang Allman-ish)
        # Pattern:
        #   if (...)
        #     stmt;
        if CONTROL.match(line) and not line.rstrip().endswith(('{', ';', '\\')):
            if i + 1 < len(lines):
                next_line = lines[i + 1]
                next_strip = next_line.strip()
                # body must be a single statement (ends with `;`) and not another block opener
                if next_strip.endswith(';') and not next_strip.endswith('};') and '{' not in next_strip:
                    head = line.rstrip()
                    result.append(f"{head} {next_strip}\n")
                    i += 2
                    continue

        result.append(line)
        i += 1

    return result


def normalize_header_comment(lines: list[str]) -> list[str]:
    """
    Reindents the leading /* ... */ block comment to 2-space indent.
    Only touches the file-header comment (starts at line 0).
    """
    if not lines or lines[0].strip() != '/*':
        return lines
    result = []
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        result.append(f"  {stripped}\n" if stripped and stripped not in ('/*', '*/') else line)
        if stripped == '*/':
            i += 1
            break
        i += 1
    result.extend(lines[i:])
    return result


# Matches lines that are exactly `ios_base::sync_with_stdio(...);`
_IOS_RE = re.compile(r'^\s*ios_base::sync_with_stdio\s*\(.*\)\s*;\s*$')
# Matches lines that are exactly `cin.tie(...);`
_TIE_RE = re.compile(r'^\s*cin\.tie\s*\(.*\)\s*;\s*$')


def join_ios_base(lines: list[str]) -> list[str]:
    """
    Joins:
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    into:
        ios_base::sync_with_stdio(0); cin.tie(0);
    """
    result = []
    i = 0
    while i < len(lines):
        if _IOS_RE.match(lines[i]) and i + 1 < len(lines) and _TIE_RE.match(lines[i + 1]):
            indent = lines[i][: len(lines[i]) - len(lines[i].lstrip())]
            ios = lines[i].strip()
            tie = lines[i + 1].strip()
            result.append(f"{indent}{ios} {tie}\n")
            i += 2
        else:
            result.append(lines[i])
            i += 1
    return result


def format_text(source: str) -> str:
    lines = source.splitlines(keepends=True)
    lines = normalize_header_comment(lines)
    lines = join_short_control_statements(lines)
    lines = join_ios_base(lines)
    lines = join_cin_reads(lines)
    return "".join(lines)


# ---------------------------------------------------------------------------
# clang-format integration
# ---------------------------------------------------------------------------

CLANG_FORMAT_CONFIG = """\
BasedOnStyle: LLVM
IndentWidth: 2
ColumnLimit: 0
AllowShortIfStatementsOnASingleLine: Never
AllowShortLoopsOnASingleLine: false
AllowShortBlocksOnASingleLine: Empty
BreakBeforeBraces: Attach
SpaceBeforeParens: ControlStatements
"""


def run_clang_format(source: str) -> str:
    """Run clang-format on source text using our embedded config via a tempdir."""
    import tempfile, os
    with tempfile.TemporaryDirectory() as tmpdir:
        # Write .clang-format so clang-format picks it up via file discovery
        cfg_path = os.path.join(tmpdir, ".clang-format")
        with open(cfg_path, "w") as f:
            f.write(CLANG_FORMAT_CONFIG)
        # Write source to a .cpp file in the same dir so style is found
        src_path = os.path.join(tmpdir, "source.cpp")
        with open(src_path, "w", encoding="utf-8") as f:
            f.write(source)
        result = subprocess.run(
            ["clang-format", src_path],
            capture_output=True,
            text=True,
            check=True,
        )
    return result.stdout


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def process_file(path: Path, inplace: bool, dry_run_diff: bool) -> bool:
    """
    Returns True if the file would be / was changed.
    """
    original = path.read_text(encoding="utf-8")

    try:
        after_clang = run_clang_format(original)
    except subprocess.CalledProcessError as e:
        print(f"[clang-format error] {path}: {e.stderr}", file=sys.stderr)
        return False

    after_cp = format_text(after_clang)

    changed = after_cp != original

    if inplace:
        if changed:
            path.write_text(after_cp, encoding="utf-8")
            print(f"[fmt] {path}")
        else:
            print(f"[ok ] {path}")
    else:
        # dry run: print result to stdout (single file) or unified diff (multi)
        if dry_run_diff:
            import difflib
            diff = list(difflib.unified_diff(
                original.splitlines(keepends=True),
                after_cp.splitlines(keepends=True),
                fromfile=f"a/{path}",
                tofile=f"b/{path}",
            ))
            if diff:
                print(f"\n{'='*60}")
                print(f"  {path}")
                print(f"{'='*60}")
                sys.stdout.writelines(diff)
            else:
                print(f"[ok ] {path}  (no changes)")
        else:
            sys.stdout.write(after_cp)

    return changed


def main():
    parser = argparse.ArgumentParser(
        description="clang-format post-processor for competitive programming C++ style."
    )
    parser.add_argument("files", nargs="+", type=Path, help=".cpp files to format")
    parser.add_argument(
        "-i", "--inplace", action="store_true",
        help="Edit files in-place (default: print to stdout / show diff)"
    )
    args = parser.parse_args()

    # If multiple files and not inplace → show unified diffs
    multi = len(args.files) > 1
    changed_count = 0

    for path in args.files:
        if not path.exists():
            print(f"[skip] {path}: file not found", file=sys.stderr)
            continue
        if process_file(path, inplace=args.inplace, dry_run_diff=multi):
            changed_count += 1

    if multi:
        total = len(args.files)
        verb = "changed" if args.inplace else "would change"
        print(f"\n{changed_count}/{total} files {verb}.")


if __name__ == "__main__":
    main()