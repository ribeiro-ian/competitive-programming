/*
 * Contest : CSES Problem Set
 * Problem : 1095 - Exponentiation
 * Link    : https://cses.fi/problemset/task/1095
 */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll bin_pow(ll a, ll b, ll m) {
  ll res = 1;
  while(b) {
    if(b&1) res = res * a % m;
    a = a*a % m;
    b = b/2;
  }
  return res;
}

int main() {
  fastio

  ll n; cin >> n;
  while(n--) {
    ll a, b;
    cin >> a >> b;
    cout << bin_pow(a, b, 1e9+7) << '\n';
  }

  return 0;
}
