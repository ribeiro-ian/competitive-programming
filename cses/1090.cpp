/**
 * Contest : CSES Problem Set
 * Problem : 1090 - Ferris Wheel
 * Link    : https://cses.fi/problemset/task/1090
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, x;
  cin >> n >> x;

  vector<ll> w(n);
  for (auto &i : w) cin >> i;
  sort(w.begin(), w.end());

  int i = 0, j = n - 1, ans = 0;
  while (i <= j) {
    if (w[i] + w[j] <= x) i++;
    j--, ans++;
  }
  cout << ans << '\n';

  return 0;
}