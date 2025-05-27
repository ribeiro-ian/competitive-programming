/*
    Neps 297 - Caminho das Pontes
    https://neps.academy/br/exercise/297
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector <vector<pii>> adj;
vector <int> dist;
vector <bool> visited;
int n, m, s, t, b;

void dijkstra(int ini) {
    dist.assign(n+2, INT_MAX);
    priority_queue <pii> fila;

    fila.push({0, ini});
    dist[ini] = 0;

    while (!fila.empty()) {
        int atual = fila.top().second;
        fila.pop();

        if (visited[atual]) continue;
        visited[atual] = true;

        for (auto &V : adj[atual]) {
            int peso = V.first, v = V.second;

            if (dist[atual] + peso < dist[v]) {
                dist[v] = dist[atual] + peso;
                fila.push({-dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%i %i", &n, &m);
    adj.assign(n+2, vector<pii>());
    visited.assign(n+2, false);

    while (m--) {
        scanf("%i %i %i", &s, &t, &b);
        adj[s].push_back({b,t});
        adj[t].push_back({b,s});
    }   

    dijkstra(0);

    printf("%i\n", dist[n+1]);

    return 0;
}