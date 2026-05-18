/*
  Maratona Mineira 2025E - Emparelhamento
  https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll N = 2e5 + 1;
vector<ll> adj[N], visited(N);
ll cnt;

void dfs(ll u) {
  visited[u] = true;
  cnt++;

  for (auto &v : adj[u])
    if (!visited[v]) dfs(v);
}

int main() {
  fastio

  ll n, a, b; cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cnt = 0;
      dfs(i);
      ans += cnt - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}