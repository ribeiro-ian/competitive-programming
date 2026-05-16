/*
  Beecrowd 1366 - Jogo de Varetas
  https://judge.beecrowd.com/pt/problems/view/1366
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
void solve() {
  int lados = 0;
  while (n--) {
    int _, x;
    cin >> _ >> x;
    lados += x / 2;
  }
  cout << lados / 2 << '\n';
}

int main() {
  fastio

  while (cin >> n, n) solve();

  return 0;
}