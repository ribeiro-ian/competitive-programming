/*
 * Contest : OBI 2025 - Fase 2
 * Problem : Placar do Jogo
 * Link    : https://neps.academy/br/exercise/3263
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int p, c, x;
  vector<pair<int, int>> gols; cin >> p;

  for (int i = 0; i < p; ++i) {
    cin >> x;
    gols.push_back({x, 0});
  }
  cin >> c;
  for (int i = 0; i < c; ++i) {
    cin >> x;
    gols.push_back({x, 1});
  }
  sort(gols.begin(), gols.end());

  cout << "0 0\n";
  pair<int, int> res = {0, 0};
  for (int i = 0; i < gols.size(); ++i) {
    if (gols[i].second) res.second++;
    else
      res.first++;

    cout << res.first << ' ' << res.second << '\n';
  }

  return 0;
}