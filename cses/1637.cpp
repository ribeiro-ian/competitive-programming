/*
 * Contest : CSES Problem Set
 * Problem : 1637 - Removing Digits
 * Link    : https://cses.fi/problemset/task/1637
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const ll INF = 1e18;
  int n; cin >> n;
  vector<ll> dp(n + 1, INF);
  dp[0] = 0;

  for (int x = 1; x <= n; ++x) {
    string s = to_string(x);
    ll mini = INF;

    for (auto &c : s) {
      ll digit = c - '0';
      if (digit <= x) mini = min(mini, dp[x - digit]);
    }

    dp[x] = mini + 1;
  }
  cout << dp[n] << '\n';

  return 0;
}
