/**
 * Contest : CSES Problem Set
 * Problem : 1619 - Restaurant Customers
 * Link    : https://cses.fi/problemset/task/1619
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;

  multiset<pair<ll, ll>> customers;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    customers.insert({a, 1});
    customers.insert({b, -1});
  }

  ll cnt = 0, ans = 0;
  for (auto [_, x] : customers) {
    cnt += x;
    ans = max(ans, cnt);
  }
  cout << ans << '\n';

  return 0;
}