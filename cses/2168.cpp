/*
 * Contest : CSES Problem Set
 * Problem : 2168 - Nested Ranges Check
 * Link    : https://cses.fi/problemset/task/2168
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  struct Range {
    int l, r, id;
  };
  vector<Range> r(n);
  vector<bool> contains(n), contained(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i].l >> r[i].r;
    r[i].id = i;
  }

  // sort by start desc, end asc
  sort(r.begin(), r.end(), [](Range a, Range b) {
    if (a.l != b.l) return a.l > b.l;
    return a.r < b.r;
  });

  auto minR = r[0].r;
  for (int i = 1; i < n; ++i) {
    if (r[i].r >= minR) contains[r[i].id] = 1;
    minR = min(minR, r[i].r);
  }

  // sort by start asc, end desc
  sort(r.begin(), r.end(), [](Range a, Range b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
  });

  auto maxR = r[0].r;
  for (int i = 1; i < n; ++i) {
    if (r[i].r <= maxR) contained[r[i].id] = 1;
    maxR = max(maxR, r[i].r);
  }

  for (auto i : contains) cout << i << ' ';
  cout << endl;
  for (auto i : contained) cout << i << ' ';
  cout << endl;

  return 0;
}
