/**
 * Contest : CSES Problem Set
 * Problem : 1081 - Common Divisors
 * Link    : https://cses.fi/problemset/task/1081
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const ll N = 1e6+1;
  ll n; cin >> n;
  
  vector<ll> freq(N, 0);
  ll maxi = 0;
  for (int i = 0; i < n; ++i) {
    ll x; cin >> x;

    maxi = max(x,maxi);
    freq[x]++;
  }
  for (ll gcd = maxi; gcd > 1; gcd--) {
    ll cnt = 0;

    for (ll d = gcd; d <= maxi; d += gcd) {
      cnt += freq[d];

      if (cnt >= 2) {
        cout << gcd << '\n';
        return 0;
      }
    }
  }
  cout << 1 << '\n';

  return 0;
}