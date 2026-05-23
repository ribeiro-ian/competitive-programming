/**
 * Contest : CSES Problem Set
 * Problem : 1074 - Stick Lengths
 * Link    : https://cses.fi/problemset/task/1074
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> sticks(n);
  for (auto &i : sticks) cin >> i;

  sort(sticks.begin(), sticks.end());
  ll median = sticks[n / 2], ans = 0;

  for (auto &i : sticks) ans += abs(median - i);
  cout << ans << '\n';

  return 0;
}