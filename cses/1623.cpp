/**
 * Contest : CSES Problem Set
 * Problem : 1623 - Apple Division
 * Link    : https://cses.fi/problemset/task/1623
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<ll> w;
ll ans = 1e18, a = 0, total = 0;

void back(int i) {
  if (i >= n) {
    ll b = total - a;
    ans = min(ans, abs(b - a));
  } else {
    a += w[i];
    back(i + 1);

    a -= w[i];
    back(i + 1);
  }
}

int main() {
  fastio

  cin >> n;
  w.resize(n);

  for (auto &i : w) {
    cin >> i;
    total += i;
  }
  back(0);
  cout << ans << '\n';

  return 0;
}
