/*
 * Contest : CSES Problem Set
 * Problem : 1634 - Minimizing Coins
 * Link    : https://cses.fi/problemset/task/1634
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n >> x;
  ll INF = 1e18;

  vector<ll> coins(n), dp(x + 1, INF);
  for (auto &i : coins) cin >> i;

  dp[0] = 0;
  for (auto &c : coins)
    for (ll i = c; i <= x; ++i) dp[i] = min(dp[i], dp[i - c] + 1);

  cout << (dp[x] != INF ? dp[x] : -1) << '\n';

  return 0;
}
