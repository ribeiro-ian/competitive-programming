/**
 * Contest : CSES Problem Set
 * Problem : 1690 - Hamiltonian Flights
 * Link    : https://cses.fi/problemset/task/1690
 * Time    : O(2^N * N^2)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const ll MOD = 1e9+7;
  ll n, m;
  cin >> n >> m;
  constexpr ll N = 4;

  vector<vector<ll>> adj(n, vector<ll>(n));
  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[--a][--b] += 1;
  }

  vector<vector<ll>> dp(1 << n, vector<ll>(n)); // {flights taken, last taken}
  dp[1][0] = 1;
  for (ll mask = 1; mask < (1 << n); ++mask) {
    if ((mask & (mask - 1)) == 0 || (mask & 1) == 0) continue; // skip if is pow of 2 or bit 0 not on

    for (ll a = 1; a < n; ++a) {
      ll pre = mask ^ (1<<a);
      if ((mask & (1 << a)) == 0) continue;
      if (pre & (1 << (n-1))) continue;

      for (ll b = 0; b < n; ++b) {
        if (pre > 1 && b == 0) continue;
        if (pre & (1 << b) && adj[b][a]) {
          dp[mask][a] = (dp[mask][a] + dp[pre][b]*adj[b][a]% MOD)% MOD;
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n-1] << '\n';

  return 0;
}