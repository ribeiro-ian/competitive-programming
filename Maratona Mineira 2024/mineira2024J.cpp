/*
  Maratona Mineira 2024 - J - Jazz
  https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/I
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int V = 2e5 + 1;
  int n; cin >> n;

  vector<int> cnt(V, 0); // quantas vezes o valor aparece
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }

  vector<int> dp(V, 0); // tamanho da maior cadeia terminando na posição
  int ans = 0;

  for (int v = 1; v < V; v++) {
    if (cnt[v] == 0) continue;
    dp[v] = max(dp[v], 1);
    for (int mul = 2 * v; mul < V; mul += v) {
      if (cnt[mul] == 0) continue;
      dp[mul] = max(dp[mul], dp[v] + 1);
    }
    ans = max(ans, dp[v]);
  }
  cout << ans << '\n';

  return 0;
}