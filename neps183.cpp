/*
    Codeforces 183 - Ilhas
    https://neps.academy/br/exercise/183
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector <vector <pii>> adj;
vector <int> dist;
vector <bool> visited;
int n, m;

void djikstra(int no) {
    dist.assign(n+1, INT_MAX);
    visited.assign(n+1, false);
    priority_queue <pii, vector <pii>, greater<pii>> q;

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
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adj.resize(n+1);

    int u, v, p;
    while (m--) {
        cin >> u >> v >> p;
        adj[u].push_back({v,p});
        adj[v].push_back({u,p});
    }

    int s; cin >> s;
    djikstra(s);

    int maior = dist[1], menor = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        maior = max(maior, dist[i]);
        if (dist[i])
            menor = min(menor, dist[i]);
        cerr << dist[i] << " ";
    }
    cerr << "\n";

    cout << abs(menor-maior) << "\n";
    cerr << "maior: " << maior << " menor: " << menor << "\n";

    return 0;
}