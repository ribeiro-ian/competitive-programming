/*
 * Contest : Codeforces
 * Problem : 50A - Domino piling
 * Link    : https://codeforces.com/problemset/problem/50/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int m, n;
  scanf("%i %i", &n, &m);

  printf("%i\n", n * m / 2);

  return 0;
}