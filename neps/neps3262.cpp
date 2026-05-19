/*
 * Contest : OBI 2025 - Fase 2
 * Problem : Arara!
 * Link    : https://neps.academy/br/exercise/3262
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m;
  cin >> n >> m;

  if (n + (n - 1) * 4 <= m) cout << "S\n";
  else
    cout << "N\n";

  return 0;
}