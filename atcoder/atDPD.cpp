/*
  AtCoder DP Contest - Knapsack 1
  https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, W;
  cin >> n >> W;
  vector<ll> w(n), v(n);

  for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

  vector<ll> dp(W + 1);

  for (int i = 0; i < n; ++i) {
    for (int j = W; j >= w[i]; --j) { dp[j] = max(dp[j], dp[j - w[i]] + v[i]); }
  }

  cout << dp[W] << '\n';

  return 0;
}