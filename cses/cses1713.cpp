/*
 * Contest : CSES
 * Problem : 1713 - Counting Divisors
 * Link    : https://cses.fi/problemset/task/1713
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll solve(int N) {
  ll cnt = 0;

  for (int i = 1; i * i <= N; i++) {
    if (N % i) continue;

    if (N / i == i) cnt++;
    else
      cnt += 2;
  }
  return cnt;
}

int main() {
  fastio

  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;

    cout << solve(n) << '\n';
  }

  return 0;
}