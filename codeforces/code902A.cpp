/*
 * Contest : Codeforces
 * Problem : 902A - Visiting a Friend
 * Link    : https://codeforces.com/contest/902/problem/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool solve() {
  int n, m, a, b, fim;
  scanf("%i %i", &n, &m);

  scanf("%i %i", &a, &fim);
  if (a) return false;
  for (int i = 1; i < n; i++) {
    scanf("%i %i", &a, &b);

    if (a > fim) return false;

    fim = max(fim, b);
  }

  return fim >= m;
}

int main() {
  fastio


  printf("%s\n", solve() ? "YES" : "NO");

  return 0;
}
