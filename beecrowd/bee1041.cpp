/*
 * Contest : Beecrowd
 * Problem : 1041 - Coordenadas de um Ponto
 * Link    : https://judge.beecrowd.com/pt/problems/view/1041
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  double x, y;
  string ans;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    ans = "Origem";
  }
  else if (x == 0) {
    ans = "Eixo Y";
  }
  else if (y == 0) {
    ans = "Eixo X";
  }
  else if (x > 0 && y > 0) {
    ans = "Q1";
  }
  else if (x < 0 && y > 0) {
    ans = "Q2";
  }
  else if (x < 0 && y < 0) {
    ans = "Q3";
  }
  else if (x > 0 && y < 0) {
    ans = "Q4";
  }

  cout << ans << '\n';

  return 0;
}