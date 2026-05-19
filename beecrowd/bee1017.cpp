/*
 * Contest : Beecrowd
 * Problem : 1017 - Gasto de Combustível
 * Link    : https://judge.beecrowd.com/pt/problems/view/1017
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int t, v;
  cin >> t >> v;

  printf("%.3f\n", t * v / 12.0);

  return 0;
}