/*
  CSES 1754 - Coin Piles
  https://cses.fi/problemset/task/1754
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool solve(ll x, ll y) {
  ll a = 2 * x - y;
  ll b = 2 * y - x;

  if (a >= 0 && a % 3 == 0 && b >= 0 && b % 3 == 0) return true;

  return false;
}

int main() {
  fastio


  int tc, x, y; cin >> tc;

  while (tc--) {
    cin >> x >> y;

    cout << (solve(x, y) ? "YES" : "NO") << '\n';
  }

  return 0;
}