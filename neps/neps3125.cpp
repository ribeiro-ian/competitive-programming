/*
  OBI 2025 - Fase 1 - Cafeteria
  https://neps.academy/br/exercise/3125
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  for (int i = 0; i * d <= c; ++i) {
    ll leite = c - i * d;
    if (leite >= a && leite <= b) {
      cout << "S\n";
      return 0;
    }
  }
  cout << "N\n";

  return 0;
}