/**
 * Contest : CSES Problem Set
 * Problem : 1196 - Flight Routes
 * Link    : https://cses.fi/problemset/task/1196
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll INF = 1e18;
vector<vector<pair<ll,ll>>> graph;
vector<ll> dist;
int n, m;

int main() {
  fastio

  cin >> n >> m;
  graph.assign(n+1, {});
  dist.assign(n+1, INF);



  return 0;
}