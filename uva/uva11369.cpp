/*
 * Contest : UVA
 * Problem : 11369 - Shopaholic
 * Link    : https://vjudge.net/problem/UVA-11369
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n; cin >> n;

  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  sort(arr.begin(), arr.end());

  int sum = 0;
  for (int i = n - 3; i >= 0; i -= 3) sum += arr[i];
  cout << sum << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}