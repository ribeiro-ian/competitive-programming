/**
 * Contest : CSES Problem Set
 * Problem : 1687 - Company Queries I
 * Link    : https://cses.fi/problemset/task/1687
 * Time    : O((N + Q) * logK)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);


int main() {
  fastio

  const int LOG = 18;
  int n, q;
  cin >> n >> q;

  vector<vector<int>> boss(LOG, vector<int> (n+1, -1));
  for (int i = 2; i <= n; ++i) cin >> boss[0][i];

  // Precomputesssss
  for (int k = 1; k < LOG; ++k) 
    for (int i = 1; i <= n; ++i) 
      boss[k][i] = boss[k-1][boss[k-1][i]];

  while (q--) {
    int x, k;
    cin >> x >> k;

    for (int i = 0; i < LOG; ++i) 
      if (k & (1 << i))
        x = boss[i][x];

    cout << (x>0? x : -1) << '\n';
  }

  return 0;
}