/**
 * Contest : CSES Problem Set
 * Problem : 2216 - Collecting Numbers
 * Link    : https://cses.fi/problemset/task/2216
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> pos(n);
  for (int i = 0; i < n; ++i) {
    ll x; cin >> x;
    pos[x] = i;
  }

  ll ans = 1;
  for (int i = 2; i <= n; ++i)
    if (pos[i] < pos[i - 1]) ans++;
  cout << ans << '\n';

  return 0;
}