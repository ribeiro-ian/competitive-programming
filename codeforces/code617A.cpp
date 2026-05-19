/*
 * Contest : Codeforces
 * Problem : 617A - Elephant
 * Link    : https://codeforces.com/problemset/problem/617/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  scanf("%i", &n);

  printf("%i\n", n / 5 + (n % 5 != 0 ? 1 : 0));

  return 0;
}