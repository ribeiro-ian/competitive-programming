/*
 * Contest : OBI 2025 - Fase 1
 * Problem : Dieta
 * Link    : https://neps.academy/br/exercise/3121
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m;
  cin >> n >> m;

  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    int p, g, c;
    cin >> p >> g >> c;

    sum += 4 * p + 9 * g + 4 * c;
  }
  cout << m - sum << '\n';

  return 0;
}