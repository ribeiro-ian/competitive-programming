/*
  Beecrowd 1661 - Comércio de Vinhos na Gergóvia
  https://judge.beecrowd.com/pt/problems/view/1661
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, v[112345];

  while (scanf("%lli", &n), n) {
    for (int i = 0; i < n; i++) scanf("%lli\n", &v[i]);

    ll amount = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      amount += v[i];
      ans += abs(amount);
    }

    printf("%lli\n", ans);
  }

  return 0;
}