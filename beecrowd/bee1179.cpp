/*
 * Contest : Beecrowd
 * Problem : 1179 - Preenchimento de Vetor IV
 * Link    : https://judge.beecrowd.com/pt/problems/view/1179
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  vector<int> par, impar;
  while (cin >> n) {
    if (n % 2) impar.push_back(n);
    else
      par.push_back(n);

    if (par.size() == 5) {
      for (int i = 0; i < 5; ++i) { printf("par[%i] = %i\n", i, par[i]); }
      par.clear();
    }
    if (impar.size() == 5) {
      for (int i = 0; i < 5; ++i) { printf("impar[%i] = %i\n", i, impar[i]); }
      impar.clear();
    }
  }

  for (int i = 0; i < impar.size(); ++i) { printf("impar[%i] = %i\n", i, impar[i]); }
  for (int i = 0; i < par.size(); ++i) { printf("par[%i] = %i\n", i, par[i]); }

  return 0;
}