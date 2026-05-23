/**
 * Contest : CSES Problem Set
 * Problem : 1672 - Shortest Routes II
 * Link    : https://cses.fi/problemset/task/1672
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll N = 501, INF = 1e18;
int n, m, q;

void floyd_warshall(vector<vector<ll>>& d) {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
}

int main() {
  fastio

  cin >> n >> m >> q;
  
  vector<vector<ll>> d(n+1, vector<ll>(n+1, INF));
  for (int i = 1; i <= n; ++i) 
      d[i][i] = 0;
  
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
  }
  floyd_warshall(d);

  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << (d[a][b] < INF? d[a][b] : -1) << '\n';  
  }

  return 0;
}