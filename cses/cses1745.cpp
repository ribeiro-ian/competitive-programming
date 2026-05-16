/*
  CSES 1745 - Money Sums
  https://cses.fi/problemset/task/1745
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

int main() {
  fastio

  ll n; cin >> n;

  vector<ll> coins(n);
  for (auto &i : coins) cin >> i;

  set<ll> ans;
  vector<bool> dp(accumulate(coins.begin(), coins.end(), 0) + 1, false);

  dp[0] = true;
  for (auto &coin : coins) {
    for (ll val = dp.size(); val >= coin; --val) {
      if (dp[val - coin]) {
        dp[val] = true;
        ans.insert(val);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) cout << i << ' ';
  cout << '\n';

  return 0;
}