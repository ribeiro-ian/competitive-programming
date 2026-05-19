/*
 * Contest : CSES
 * Problem : 1618 - Trailing Zeros
 * Link    : https://cses.fi/problemset/task/1618
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  int n; cin >> n;

  int cnt = 0;
  for (int i = 5; n / i >= 1; i *= 5) { cnt += n / i; }
  cout << cnt << '\n';

  return 0;
}