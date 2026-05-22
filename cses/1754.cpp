/*
 * Contest : CSES Problem Set
 * Problem : 1754 - Coin Piles
 * Link    : https://cses.fi/problemset/task/1754
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) {
    ll a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    if ((a + b) % 3 == 0 && 2 * a >= b) cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
