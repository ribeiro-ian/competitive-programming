/*
 * Contest : Beecrowd
 * Problem : 2227 - Aeroporto
 * Link    : https://judge.beecrowd.com/pt/problems/view/2227
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int a, v, x, y, teste = 1;

  while (scanf("%i%i", &a, &v), a && v) {
    vector<int> voos(a + 1, 0);

    int maior = 0;
    for (int i = 0; i < v; i++) {
      scanf("%i%i", &x, &y);

      voos[x]++;
      voos[y]++;
      maior = max(maior, max(voos[x], voos[y]));
    }

    printf("Teste %i\n", teste++);
    for (int i = 1; i <= a; i++) {
      if (voos[i] == maior) printf("%i ", i);
    }
    printf("\n\n");
  }

  return 0;
}
