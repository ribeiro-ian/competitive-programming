/*
 * Contest : AtCoder Beginner Contest 169
 * Problem : D - Div Game
 * Link    : https://atcoder.jp/contests/abc169/tasks/abc169_d
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  ll ans = 0;
  for (ll p = 2; p * p <= n; ++p) {
    ll e = 0;
    while (n % p == 0) {
      e++;
      n /= p;
      cerr << n << endl;
    }

    for (ll i = 1; i <= e; ++i) {
      e -= i;
      ans++;
    }
  }
  ans += (n > 1);

  cout << ans << endl;

  return 0;
}