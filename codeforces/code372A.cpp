/*
 * Contest : Codeforces
 * Problem : 327A - Counting Kangaroos is Fun
 * Link    : https://codeforces.com/problemset/problem/372/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  scanf("%i", &n);

  int s[n];
  for (int i = 0; i < n; i++) scanf("%i", &s[i]);

  sort(s, s + n);

  int cnt = n, l = 0, r = n / 2;
  while (l < n / 2 && r < n) {
    if (s[l] * 2 <= s[r]) {
      cnt--;
      l++;
    }
    r++;
  }

  printf("%i\n", cnt);

  return 0;
}