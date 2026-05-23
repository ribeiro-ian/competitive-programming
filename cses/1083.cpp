/**
 * Contest : CSES Problem Set
 * Problem : 1083 - Missing Number
 * Link    : https://cses.fi/problemset/task/1083
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, x, sum = 0; cin >> n;

  for (int i = 1; i < n; ++i) {
    cin >> x;
    sum += x;
  }

  cout << n * (n + 1) / 2 - sum << '\n';

  return 0;
}