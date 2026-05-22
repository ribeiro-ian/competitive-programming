/*
 * Contest : CSES Problem Set
 * Problem : 1632 - Movie Festival II
 * Link    : https://cses.fi/problemset/task/1632
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> movies(n);
  for (auto &[st, end] : movies) cin >> end >> st;

  sort(movies.begin(), movies.end());

  multiset<ll> busy, free;
  for (int i = 0; i < k; ++i) free.insert(0);

  ll cnt = 0;
  for (const auto &[end, st] : movies) {
    while (!busy.empty() && *busy.begin() <= st) {
      free.insert(*busy.begin());
      busy.erase(busy.begin());
    }
    if (!free.empty()) {
      auto it = free.upper_bound(st); // first end > st

      if (it != free.begin()) {
        --it;
        busy.insert(end);
        free.erase(it);
        cnt++;
      }
    }
  }
  cout << cnt << '\n';

  return 0;
}
