/**
 * Contest : CSES Problem Set
 * Problem : 3420 - Distinct Values Subarrays
 * Link    : https://cses.fi/problemset/task/3420
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) cin >> i;

  set<int> s;
  ll ans = 0;
  for (int l = 0, r = 0; l < n;) {
    while (r < n && !s.count(arr[r])) s.insert(arr[r++]);

    ans += r - l;
    s.erase(arr[l++]);
  }
  cout << ans << '\n';

  return 0;
}
