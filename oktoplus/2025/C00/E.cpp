/*
  Beecrowd 2963 - Bobo da Corte
  https://judge.beecrowd.com/pt/problems/view/2963
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;

  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i];

  int carlos = v[0];

  sort(v, v + n);

  printf("%c\n", carlos == v[n - 1] ? 'S' : 'N');

  return 0;
}
