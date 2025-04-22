/*
    Neps 296 - Desvio de Rota
    https://neps.academy/br/exercise/296
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector <vector <pii>> adj;
vector <int> dist;
vector <bool> visited;
int n, m, c, k;

void dijkstra(int no) {
    dist.assign(n, INT_MAX);
    visited.assign(n, false);
    priority_queue <pii> q;

    dist[no] = 0;
    q.push({0, no});

    while (!q.empty()) {
        int curr = q.top().second;
        q.pop();
        
        if (visited[curr]) continue;
        visited[curr] = true;
        
        for (auto &V : adj[curr]) {
            int v = V.first, w = V.second;
            if (dist[curr] + w < dist[v]) {
                dist[v] = dist[curr] + w;
                q.push({-dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> m >> c >> k, n) {
        adj.assign(n, vector<pii>());

        int u, v, p;
        while (m--) {
            cin >> u >> v >> p;

            // rota de serviço: < c; fora da rota: >= c
            if (u >= c && v >= c) {
                adj[u].push_back({v, p});
                adj[v].push_back({u, p});
            }
            else if (u >= c && v < c) {
                adj[u].push_back({v, p});
            }
            else if (v >= c && u < c) {
                adj[v].push_back({u, p});
            }
            else if (abs(u-v) == 1) {
                adj[min(u,v)].push_back({max(u,v),p});
            }
        }

        dijkstra(k);
        cout << dist[c-1] << "\n";
    }

    return 0;
}