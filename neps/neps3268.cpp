/*
 * Contest : OBI 2025 - Fase 2
 * Problem : Um Desafio Muito Distinto
 * Link    : https://neps.academy/br/exercise/3268
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool isValid(ll a, ll n, ll target) {
  n--;
  return n * (2 * a + n - 1) / 2 < target; //
}

ll bs(ll target, ll a, ll b) {
  ll l = 1, r = b - a + 1, m, ans = -1;

  while (l <= r) {
    m = l + (r - l) / 2;

    if (isValid(a, m, target)) {
      l = m + 1;
      ans = m;
    } else
      r = m - 1;
  }
  return ans;
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) {
    ll target, a, b;
    cin >> target >> a >> b;

    cout << bs(target, a, b) << '\n';
  }

  return 0;
}