/*
 * Contest : Codeforces
 * Problem : 282A - Bit++
 * Link    : https://codeforces.com/problemset/problem/282/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int n;
  string str;
  scanf("%i", &n);

  int ans = 0;
  while (n--) {
    cin >> str;

    if (str[1] == '+') ans++;
    else
      ans--;
  }
  printf("%i\n", ans);

  return 0;
}