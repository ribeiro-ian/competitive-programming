/*
 * Contest : Codeforces
 * Problem : 155A - I_love_%username%
 * Link    : https://codeforces.com/problemset/problem/155/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int MAX = 1e4 + 1;
  int n, x;

  scanf("%i", &n);

  scanf("%i", &x);
  int best = x, worst = x, cnt = 0;
  for (int i = 1; i < n; i++) {
    scanf("%i", &x);

    if (x > best) {
      best = x;
      cnt++;
    }
    if (x < worst) {
      worst = x;
      cnt++;
    }
  }

  printf("%i\n", cnt);

  return 0;
}