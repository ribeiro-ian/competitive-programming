/*
    CSES 1673 - High Score
    https://cses.fi/problemset/task/1673
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
 
const INF = 1e18;
vector <vector <pll>> adj;
ll n, m;
 
vector<int> bellmanFord(int V, int src) {
	vector<int> dist(V, 1e18);
	dist[src] = 0;
  
	// Relaxation of all the adj V times, not (V - 1) as we
    // need one additional relaxation to detect negative cycle
	for (int i = 0; i < V; i++) {
	    
		for (vector<int> v : adj) {
			int u = v[0];
			int v = v[1];
			int wt = v[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			    
                // If this is the Vth relaxation, then there is
                // a negative cycle
                if(i == V - 1)
                    return {-1};
               
                // Update shortest distance to node v
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m >> q; 
    adj.assign(n+1, vector <ll>());
 
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back(c);
    }
    floyd_warshall();
 
    while (q--) {
        cin >> a >> b;
        cout << (d[a][b] != INF ? d[a][b] : -1) << '\n';
    }
 
    return 0;
}