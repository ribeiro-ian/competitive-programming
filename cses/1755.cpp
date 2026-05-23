/**
 * Contest : CSES Problem Set
 * Problem : 1755 - Palindrome Reorder
 * Link    : https://cses.fi/problemset/task/1755
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  fastio

  map<char, int> mp;
  string s; cin >> s;

  for (auto &c : s) mp[c]++;

  bool flag = true;
  int odd_cnt = 0;
  char mid;

  for (auto &m : mp) {
    if (m.second & 1) {
      odd_cnt++;
      mid = m.first;
    }
    if (odd_cnt > 1) {
      flag = false;
      break;
    }
  }

  if (!flag) {
    cout << "NO SOLUTION\n";
  } else {
    string res = "";
    for (auto &m : mp) {
      if (m.second % 2) continue;

      for (int i = 0; i < m.second / 2; ++i) res += m.first;
    }
    string aux = res;
    reverse(aux.begin(), aux.end());

    if (mid)
      for (int i = 0; i < mp[mid]; i++) res += mid;

    res += aux;
    cout << res << '\n';
  }

  return 0;
}
