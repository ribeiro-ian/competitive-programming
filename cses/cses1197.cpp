/*
    CSES 1197 - Cycle Finding
    https://cses.fi/problemset/task/1197
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1e18;
vector <vector <ll>> graph;
vector<ll> par;
ll n, m, x;
 
bool bellmanFord() {
    // Inicializar com 0, pois só interessa se existe cyclo negativo (< 0)
	vector<ll> dist(n+1, 0);
	par.assign(n+1, -1);
    
	for (int i = 0; i < n; i++) {
        x = -1;
		for (auto &edge : graph) {
			ll u = edge[0], v = edge[1], w = edge[2];
			if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;

                x = v;
            }
		}
	}

    return (x == -1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m; 

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        graph.push_back({a,b,c});
    }

    if (bellmanFord()) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) 
            x = par[x];
    
        vector<int> cycle;
        for (ll v = x;; v = par[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) 
                break;
        }
        reverse(cycle.begin(), cycle.end());
        
        for (auto &i : cycle) 
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}