/*
  Maratona Mineira 2024 - E - Motorista de ônibus
  https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0)

int main() {
  fastio;

  ll n; cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &i : v) cin >> i.first >> i.second;
  sort(v.begin(), v.end());

  vector<ll> ruas(n);
  for (int i = 0; i < n; ++i) ruas[i] = v[i].first;

  int i = 0;
  ll ans = 0, aux = 0, meio = -1;
  while (i < n) {
    auto [rua, pos] = v[i];

    if (rua != aux) {
      aux = rua;
      int primeiro = i;

      auto it = upper_bound(ruas.begin(), ruas.end(), rua);
      it--;
      int ultimo = it - ruas.begin();
      // cerr << primeiro << " " << ultimo << '\n';
      meio = primeiro + (ultimo - primeiro) / 2;
      // cerr << v[meio].second << '\n';
    }

    ans += abs(pos - v[meio].second);
    i++;
  }
  cout << ans << '\n';

  return 0;
}