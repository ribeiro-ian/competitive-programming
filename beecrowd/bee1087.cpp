/*
 * Contest : Beecrowd
 * Problem : 1087 - Dama
 * Link    : https://judge.beecrowd.com/pt/problems/view/1087
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int x1, y1, x2, y2;
  while (1) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (!x1 && !y1 && !x2 && !y2) break;

    if (x1 == x2 && y1 == y2) cout << "0\n";
    else if (abs(x1 - x2) == abs(y1 - y2) || x1 == x2 || y1 == y2) cout << "1\n";
    else
      cout << "2\n";
  }

  return 0;
}