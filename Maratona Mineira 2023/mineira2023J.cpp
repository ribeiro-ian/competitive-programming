/*
 * Contest : Maratona Mineira 2023
 * Problem : J - Jogo dos Copos
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/446227/problem/J
 * Time    : O(N * T)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, t; cin >> n >> t;

  vector<vector<pair<ll, ll>>> cen(t+1);
  for (int i = 0; i < n; ++i){
    ll pes, tam, maj;
    cin >> pes >> tam >> maj;

    cen[tam].push_back({pes, maj});
  }

  vector<ll> s(t+1);
  for (ll i = 1; i <= t; ++i) {
    ll a, b;
    cin >> a >> b;
    s[i] = min(a,b)*2;
  }

  ll res = 0;
  vector<pair<ll, ll>> dp(t+1);
  for (ll tam = 1; tam <= t; ++tam) {
    if (!s[tam]) continue;
    // knapsack 0/1

    // reverso
    vector<pair<ll,ll>> dp(s[tam]+1);
    auto& c = cen[tam];

    dp[0] = {0,0};
    for (auto& [pes, maj] : c) {
      for (int x = s[tam]; x >= 0; --x) {
        if (x - pes >= 0 && dp[x-pes].second + maj > dp[x].second) {
          dp[x] = {dp[x-pes].first + pes, dp[x-pes].second + maj};
        }
      }
    }

    res += dp[s[tam]].second;
  }
  cout << res << '\n';

  return 0;
}