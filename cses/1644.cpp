/*
 * Contest : CSES Problem Set
 * Problem : 1644 - Maximum Subarray Sum II
 * Link    : https://cses.fi/problemset/task/1644
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, a, b;
  cin >> n >> a >> b;

  vector<ll> right(n + 1);
  multiset<ll> left;
  ll ans = -LLONG_MAX;

  // keep R fixed and remove the best L possible (smallest prefix)
  for (int i = 1; i <= n; ++i) {
    cin >> right[i];
    right[i] += right[i - 1];

    if (i >= a) left.insert(right[i - a]);
    if (i > b) left.erase(left.find(right[i - b - 1]));
    if (!left.empty()) ans = max(ans, right[i] - *left.begin());
  }
  cout << ans << '\n';

  return 0;
}
