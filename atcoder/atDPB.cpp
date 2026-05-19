/*
 * Contest : AtCoder Educational DP Contest
 * Problem : B - Frog 2
 * Link    : https://atcoder.jp/contests/dp/tasks/dp_b
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for (auto &i : vec) cin >> i;

  vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for (int i = 1, j; i < n; i++) {
    j = i - 1;

    while (j >= 0 && i - j <= k) {
      dp[i] = min(dp[i], dp[j] + abs(vec[i] - vec[j]));
      j--;
    }
  }

  cout << dp[n - 1] << "\n";

  return 0;
}