/*
 * Contest : UVA
 * Problem : 10020 - Minimal Coverage
 * Link    : https://vjudge.net/problem/UVA-10020
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int m; cin >> m;
  vector<pair<int, int>> seg;

  int l, r;
  while (cin >> l >> r, l or r)
    if (r > 0 && l < m)
      seg.push_back({l, r});
  sort(seg.begin(), seg.end());

  vector<pair<int, int>> chosen;
  int left = 0, i = 0, n = seg.size();
  bool flag = true;

  while (left < m) {
    // entre todos com l <= left, pega o de maior R
    int right = left, idx = -1;
    while (i < n && seg[i].first <= left) {
      if (seg[i].second > right) {
        right = seg[i].second;
        idx = i;
      }
      i++;
    }
    if (idx == -1) {
      flag = false;
      break;
    }
    chosen.push_back(seg[idx]);
    left = right;
  }

  if (!flag) cout << 0 << '\n';
  else {
    cout << chosen.size() << '\n';
    for (auto &[l, r] : chosen) cout << l << ' ' << r << '\n';
  }
  cout << '\n';
}
int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}