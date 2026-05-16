/*
  Beecrowd 2702 - Escolha Difícil
  https://judge.beecrowd.com/pt/problems/view/2702
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int x, v[3], ans = 0;

  for (int i = 0; i < 3; i++) { scanf("%i", &v[i]); }
  for (int i = 0; i < 3; i++) {
    scanf("%i", &x);

    ans += max(0, x - v[i]);
  }

  printf("%i\n", ans);

  return 0;
}
