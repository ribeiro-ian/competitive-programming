/**
 * Contest : CSES Problem Set
 * Problem : 1091 - Concert Tickets
 * Link    : https://cses.fi/problemset/task/1091
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, m, x;
  cin >> n >> m;

  multiset<ll> prices;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    prices.insert(x);
  }

  while (m--) {
    cin >> x;
    auto it = prices.upper_bound(x);

    if (it == prices.begin()) cout << -1 << '\n';
    else {
      cout << *(--it) << '\n';
      prices.erase(it);
    }
  }

  return 0;
}