/**
 * Contest : CSES Problem Set
 * Problem : 2183 - Missing Coin Sum
 * Link    : https://cses.fi/problemset/task/2183
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> coins(n);
  for (auto &i : coins) cin >> i;
  sort(coins.begin(), coins.end());

  ll sum = 1;
  for (auto &i : coins) {
    if (i > sum) break;
    else
      sum += i;
  }
  cout << sum << '\n';

  return 0;
}