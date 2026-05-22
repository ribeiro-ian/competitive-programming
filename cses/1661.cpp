/*
 * Contest : CSES Problem Set
 * Problem : 1661 - Subarray Sums II
 * Link    : https://cses.fi/problemset/task/1661
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, x;
  cin >> n >> x;

  map<ll, ll> freq;
  freq[0] = 1;

  ll cnt = 0;
  vector<ll> pref(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> pref[i];
    pref[i] += pref[i - 1];

    cnt += freq[pref[i] - x];
    freq[pref[i]] += 1;
  }
  cout << cnt << '\n';

  return 0;
}
