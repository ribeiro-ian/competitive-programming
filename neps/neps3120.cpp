/*
  OBI 2025 - Fase 1 - Café com Leite
  https://neps.academy/br/exercise/3120
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int leite = c - d;
  if (leite >= a && leite <= b) cout << "S\n";
  else
    cout << "N\n";

  return 0;
}