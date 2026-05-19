/*
 * Contest : Beecrowd
 * Problem : 2520 - O Último Analógimôn
 * Link    : https://judge.beecrowd.com/pt/problems/view/2520
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m;
  while (cin >> n >> m) {
    pair<int, int> eu, bixo;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x; cin >> x;

        if (x == 1)
          eu = {i, j};
        else if (x == 2)
          bixo = {i, j};
      }
    }
    cout << abs(eu.first - bixo.first) + abs(eu.second - bixo.second) << '\n';
  }

  return 0;
}