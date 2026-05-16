/*
  CSES 1091 - Concert Tickets
  https://cses.fi/problemset/task/1091
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, k, x;

int main() {
  fastio

  cin >> n >> k;
  multiset<ll> v;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    v.insert(x);
  }
  for (int i = 0; i < k; ++i) {
    cin >> x;

    auto it = v.upper_bound(x);

    if (it == v.begin()) {
      cout << -1 << "\n";
    }
    else {
      cout << *(--it) << "\n";
      v.erase(it);
    }
  }

  return 0;
}