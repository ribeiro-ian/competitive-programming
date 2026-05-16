/*
  CSES 1662 - Subarray Divisibility
  https://cses.fi/problemset/task/1662
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;

  map<ll, ll> memo;
  memo[0] += 1;

  ll remainder = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    ll x; cin >> x;

    // resto não negativo
    remainder = ((remainder + x) % n + n) % n;
    cnt += memo[remainder];
    memo[remainder] += 1;
  }

  cout << cnt << '\n';

  return 0;
}