/*
 * Contest : CSES Problem Set
 * Problem : 1617 - Bit Strings
 * Link    : https://cses.fi/problemset/task/1617
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll M = 1e9 + 7;
ll exp(ll x, ll e) {
  x %= M;
  ll res = 1;
  while (e) {
    if (e & 1) res = res * x % M;
    x = x * x % M;
    e /= 2;
  }
  return res;
}

int main() {
  fastio

  ll n; cin >> n;
  cout << exp(2, n) << '\n';

  return 0;
}