/**
 * Contest : CSES Problem Set
 * Problem : 1629 - Movie Festival
 * Link    : https://cses.fi/problemset/task/1629
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<pair<ll, ll>> movies(n);

  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    movies[i] = {b, a};
  }
  sort(movies.begin(), movies.end());

  ll ending = movies.front().first, ans = 1;
  for (auto &[end, st] : movies) {
    if (st >= ending) {
      ending = end;
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}