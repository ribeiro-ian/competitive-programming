/*
  CSES 1619 - Restaurant Customers
  https://cses.fi/problemset/task/1619
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, a, b; cin >> n;
  vector<pair<ll, bool>> v;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    // true = arriving, false = leaving
    v.push_back({a, true});
    v.push_back({b, false});
  }
  sort(v.begin(), v.end());

  ll cnt = 0, ans = 0;
  for (auto [_, flag] : v) {
    cnt += (flag ? 1 : -1);
    ans = max(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}