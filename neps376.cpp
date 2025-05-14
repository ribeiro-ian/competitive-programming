/*
    NEPS 376 - Caminhos Mínimos
    https://neps.academy/br/exercise/376
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

vector <vector<pii>> adj;
vector <bool> visitado;
vector <ll> max_dist, min_dist, max_nivel, min_nivel;
ll n, m;
const ll INF = 1e18;

void menor_caminho(ll s) {
    visitado.assign(n+1, false);
    min_dist.assign(n+1, INF);
    min_nivel.assign(n+1, INF);

    priority_queue <pii> q;
    q.push({0, s});
    min_dist[s] = min_nivel[s] = 0;

    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();

        if (visitado[u]) continue;
        visitado[u] = true;

        for (auto [v, w] : adj[u]) {
            
            if (min_dist[u] + w < min_dist[v]) {
                min_nivel[v] = min(min_nivel[v], min_nivel[u]+1);
                min_dist[v] = min_dist[u] + w;
                q.push({-min_dist[v], v});
            }
        }
    }
}
void caminho_direto(ll s) {
    visitado.assign(n+1, false);
    max_dist.assign(n+1, 0);
    max_nivel.assign(n+1, -1);

    queue <ll> q;
    q.push(s);
    max_dist[s] = max_nivel[s] = 0;

    while (!q.empty()) {
        ll u = q.top();
        q.pop();

        visitado[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                max_nivel[v] = max_nivel[u]+1;
                max_dist[v] = max_dist[u] + w;
                q.push({max_dist[v], v});
            }
        }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adj.assign(n+1, vector<pii>());

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    menor_caminho(1);
    caminho_direto(1);

    for (int i = 1; i <= n; ++i) {
        cerr << "No " << i << ":\n";
        cerr << "Max: dist = " << max_dist[i] << " nivel = " << max_nivel[i] << "\n"; 
        cerr << "Min: dist = " << min_dist[i] << " nivel = " << min_nivel[i] << "\n\n"; 
    }

    
    return 0;
}