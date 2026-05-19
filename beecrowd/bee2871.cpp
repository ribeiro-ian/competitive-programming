/*
 * Contest : Beecrowd
 * Problem : 2871 - Colheita de Café
 * Link    : https://judge.beecrowd.com/pt/problems/view/2871
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m;
  while (cin >> n >> m) {
    int sum = 0, x;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> x;
        sum += x;
      }
    int sacks = sum / 60;
    int rest = sum - 60 * sacks;
    cout << sacks << " saca(s) e " << rest << " litro(s)\n";
  }

  return 0;
}