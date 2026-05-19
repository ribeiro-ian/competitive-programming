/*
 * Contest : Maratona Mineira 2022
 * Problem : C - Caindo na estrada
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/C
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> vec(n);
  for (auto &i : vec) cin >> i;

  vector<ll> dp(n, 0);
  if (n == 1) {
    cout << vec[0] << "\n";
    return 0;
  }

  dp[0] = vec[0];
  dp[1] = max(vec[0], vec[1]);

  for (int i = 2; i < n; ++i) { dp[i] = max(dp[i - 1], vec[i] + dp[i - 2]); }

  cout << dp[n - 1] << "\n";

  return 0;
}