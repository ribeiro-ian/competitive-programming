/*
 * Contest : Codeforces
 * Problem : 2074A - Draw a Square
 * Link    : https://codeforces.com/contest/2074/problem/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int tc, l, r, d, u;
  scanf("%i", &tc);

  while (tc--) {

    scanf("%i%i%i%i", &l, &r, &d, &u);

    if (l == r & r == d & d == u) printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}