/*
 * Contest : CSES
 * Problem : 1074 - Stick Lengths
 * Link    : https://cses.fi/problemset/task/1074
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> v(n);

  for (auto &i : v) cin >> i;

  sort(v.begin(), v.end());
  for (auto &i : v) cerr << i << ' ';
  cerr << '\n';
  ll ans = 0, m = v[n / 2];
  for (auto &i : v) { ans += abs(i - m); }

  cout << ans << '\n';

  return 0;
}