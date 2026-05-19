/*
 * Contest : CSES
 * Problem : 1617 - Bit Strings
 * Link    : https://cses.fi/problemset/task/1617
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll MOD = 1e9 + 7;
ll power(ll base, ll expo) {
  ll ans = 1;
  while (expo) {
    if (expo % 2) ans = (ans * base) % MOD;

    base = (base * base) % MOD;
    expo /= 2;
  }
  return ans;
}

int main() {
  fastio

  ll n; cin >> n;
  cout << power(2LL, n) % MOD << endl;

  return 0;
}