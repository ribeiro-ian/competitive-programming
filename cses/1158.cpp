/*
 * Contest : CSES Problem Set
 * Problem : 1158 - Book Shop
 * Link    : https://cses.fi/problemset/task/1158
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n >> x;

  vector<int> price(n), pages(n), dp(x + 1);
  for (auto &i : price) cin >> i;
  for (auto &i : pages) cin >> i;

  for (int i = 0; i < n; ++i)
    for (int j = x - price[i]; j >= 0; --j) dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);

  cout << dp[x] << '\n';

  return 0;
}
