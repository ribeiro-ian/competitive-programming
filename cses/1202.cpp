/*
 * Contest : CSES Problem Set
 * Problem : 1202 - Investigation
 * Link    : https://cses.fi/problemset/task/1202
 * Time    : O(M * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
const ll MOD = 1e9+7, INF = 1e18;
vector<vector<pair<ll,ll>>> graph;

void dijkstra() {
  vector<ll> price(n+1, INF), ways(n+1,0), mini(n+1, INF), maxi(n+1, 0); 
  price[1] = mini[1] = maxi[1] = 0;
  ways[1] = 1;

  priority_queue<pair<ll,ll>> q;
  q.push({0, 1});

  while (!q.empty()) {
    auto [pu, u] = q.top();
    q.pop();

    if (-pu > price[u]) continue;
    
    for (auto& [v,w] : graph[u]) {
      if (price[v] > price[u] + w) {
        ways[v] = ways[u];
        maxi[v] = maxi[u]+1;
        mini[v] = mini[u]+1;
        
        price[v] = price[u] + w;
        q.push({-price[v], v});
      }
      else if (price[v] == price[u] + w) {
        ways[v] = (ways[v] + ways[u]) % MOD;
        maxi[v] = max(maxi[v], maxi[u]+1);
        mini[v] = min(mini[v], mini[u]+1);
      }
    }
  }
  
  cout << price[n] << ' ' << ways[n] << ' ' << mini[n] << ' ' << maxi[n] << '\n';
}

int main() {
  fastio

  cin >> n >> m;
  graph.assign(n+1, {});

  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
  }
  
  dijkstra();

  return 0;
}