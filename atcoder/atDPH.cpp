/*
 * Contest : AtCoder Educational DP Contest
 * Problem : H - Grid 1
 * Link    : https://atcoder.jp/contests/dp/tasks/dp_h
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int MOD = 1e9+7;
  int h, w;
  cin >> h >> w;
  char grid[h+1][w+1];
  
  for (int i = 1; i < h+1; ++i) 
    for (int j = 1; j < w+1; ++j) 
     cin >> grid[i][j];
  
  int dp[h+1][w+1];
  memset(dp, 0, sizeof(dp));
  
  dp[1][0] = 1;
  for (int i = 1; i < h+1; ++i) 
    for (int j = 1; j < w+1; ++j) 
      if (grid[i][j] == '.') 
       dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    
  cout << dp[h][w] << '\n';
  
  return 0;
}