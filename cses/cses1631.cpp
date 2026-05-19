/*
 * Contest : CSES
 * Problem : 1631 - Reading Books
 * Link    : https://cses.fi/problemset/task/1631
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, sum = 0; cin >> n;
  vector<ll> v(n);
  for (auto &i : v) {
    cin >> i;
    sum += i;
  }

  sort(v.begin(), v.end());

  if (v[n - 1] > sum - v[n - 1]) {
    cout << v[n - 1] * 2 << '\n';
  }
  else {
    cout << sum << '\n';
  }

  return 0;
}