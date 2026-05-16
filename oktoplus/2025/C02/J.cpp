/*
  Beecrowd 2518 - Escada do DINF
  https://judge.beecrowd.com/pt/problems/view/2518
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, h, c, l;
  while (cin >> n) {
    cin >> h >> c >> l;

    double ans = l * sqrt(pow(h, 2) + pow(c, 2));

    printf("%.4f\n", ans * n / 10e3);
  }

  return 0;
}
