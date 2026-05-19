/*
 * Contest : Codeforces
 * Problem : 2149C - MEX rose
 * Link    : https://codeforces.com/problemset/problem/2149/C
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<bool> freq(k, 0);
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    ll x; cin >> x;
    cnt += (x == k);
    if (x < k) freq[x] = true;
  }

  ll ans = 0;
  for (auto i : freq) ans += !i;

  cout << max(ans, cnt) << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}