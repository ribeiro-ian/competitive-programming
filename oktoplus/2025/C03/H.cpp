/*
  Beecrowd 2579 - Nagol
  https://judge.beecrowd.com/pt/problems/view/2579
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int l, c, x, y;
  cin >> l >> c >> x >> y;

  if (c % 2 == 1) {
    if (x % 2 == y % 2) printf("Direita\n");
    else
      printf("Esquerda\n");
  }
  else {
    if (y % 2 == 0) printf("Direita\n");
    else
      printf("Esquerda\n");
  }

  return 0;
}
