/*
 * Contest : CSES
 * Problem : 1630 - Tasks and Deadlines
 * Link    : https://cses.fi/problemset/task/1630
 */

#include <bits/stdc++.h>
#include <print>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
typedef pair<ll, ll> pll;

int main() {
  fastio

  ll n, time = 0; cin >> n;

  vector<pll> v(n);
  for (auto &i : v) cin >> i.first >> i.second;

  sort(v.begin(), v.end());

  ll ans = 0;
  for (auto &[t, d] : v) {
    time += t;

    ans += d - time;
  }

  cout << ans << '\n';

  return 0;
}