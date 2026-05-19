/*
 * Contest : Codeforces
 * Problem : 946A - Partition
 * Link    : https://codeforces.com/contest/946/problem/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int n, x;
  scanf("%i", &n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%i", &x);

    sum += abs(x);
  }

  printf("%i\n", sum);

  return 0;
}
