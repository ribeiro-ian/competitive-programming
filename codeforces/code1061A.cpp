/*
  Codeforce 1061A - Coins
  https://codeforces.com/contest/1061/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int n, s;
  scanf("%i %i", &n, &s);

  int ans = 0;
  for (int i = n; i >= 1 && s; i--) {
    ans += s / i;
    s -= i * (s / i);
  }

  printf("%i\n", ans);

  return 0;
}
