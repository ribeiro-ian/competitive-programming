/*
    Beecrowd 1391 - Quase menor caminho
    https://judge.beecrowd.com/pt/problems/view/1391
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int n, m, s, d;
const int INF = INT_MAX;
vector <vector <int>> adj;
vector <int> previous, dist;
vector <bool> visited;

int dijkstra(int s) {
    dist.assign(n, INF);
    previous.assign(n, -1);
    visited.assign(n, false);
    priority_queue <pii> q;

    previous[s] = s;
    dist[s] = 0;
    q.push({0, s});
    
    while (!q.empty()) {
        int curr = q.top().second;
        q.pop();

        if (visited[curr]) continue;
        visited[curr] = true;
        
        for (int v = 0; v < n; v++) {
            int w = adj[curr][v];
            if (w && dist[curr] + w < dist[v]) {
                previous[v] = curr;
                dist[v] = dist[curr] + w;
                q.push({-dist[v], v});
            }
        }
    }

    return dist[d];
}

void removeEdges(int no) {
    if (previous[no] == -1) return;

    while(no != previous[no]) {
        fprintf(stderr, "removido %i -> %i\n", previous[no], no);
        adj[previous[no]][no] = 0;
        no = previous[no];
    }
    adj[previous[no]][no] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> m, n) {
        adj.assign(n, vector<int>(n, 0));
        
        cin >> s >> d;
        
        int u, v, p;
        while (m--) {
            cin >> u >> v >> p;
            adj[u][v] = p;
        }

        int menor, ans;
        menor = ans = dijkstra(s);
        
        // remover nós que formam menor caminho
        while (ans == menor) {
            cerr << "previous:\n";
            for (auto &i : previous)
                cerr << i << " "; cerr << "\n";
            removeEdges(d);
            ans = dijkstra(s);
            
            if (ans == INF || previous[d] == -1) {
                ans = -1;
                break;
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}