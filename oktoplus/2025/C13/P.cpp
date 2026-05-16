/*
  CSES 2183 - Missing Coin Sum
  https://cses.fi/problemset/task/2183
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> v(n);
  for (auto &i : v) { cin >> i; }
  sort(v.begin(), v.end());

  ll sum = 1;
  for (auto &i : v) {
    if (i > sum) { break; }
    sum += i;
  }

  cout << sum << endl;

  return 0;
}