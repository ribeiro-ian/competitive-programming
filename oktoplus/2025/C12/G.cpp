#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll solve(ll x) {
  ll cnt = 0;

  for (int i = 2; i * i <= x; ++i) { cnt += x / (i * i); }

  return x + cnt;
}

int main() {
  fastio

  ll t, n; cin >> t;
  while (t--) {
    cin >> n;
    cout << solve(n) << '\n';
  }

  return 0;
}