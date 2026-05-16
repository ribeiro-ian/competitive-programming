/*
  CSES 1661 - Subarray Sums II
  https://cses.fi/problemset/task/1661
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, k;
  cin >> n >> k;

  vector<ll> pref(n + 1);
  map<ll, ll> memo;
  memo[0] = 1;

  ll x, cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }

  for (int i = 1; i <= n; ++i) {
    cnt += memo[pref[i] - k];
    memo[pref[i]] += 1;
  }

  cout << cnt << '\n';

  return 0;
}