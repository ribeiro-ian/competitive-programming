/*
    Maratona Mineira 2025 - G - GPS
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/G
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c, p;
const ll N = 5e5+1, INF = 1e18;
vector<pair<ll,ll>> pe[N], carro[N];
vector<ll> peDe1(N), peParaN(N), dist(N);
ll ans = INF;

void dijkstraPe(int s, vector<ll>& d){
    d.assign(n+1, INF);
    priority_queue<pair<ll,ll>> pq;
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();
        if(-du > d[u]) continue;
        
        for(auto& [v,w] : pe[u]){
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                pq.push({-d[v], v});
            }
        }
    }
}

void dijkstraCarro(){
    dist.assign(n+1, INF);
    priority_queue<pair<ll,ll>> pq;
    for(int i = 1; i <= n; ++i){
        if(peDe1[i] != INF){
            dist[i] = peDe1[i]; // considera primeiro que percoreu até o nó i a pé
            pq.push({-dist[i], i}); 
        }
    }

    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();

        if(-du > dist[u]) continue; // <- faltava isso
        if(peParaN[u] != INF)
            ans = min(ans, dist[u]+peParaN[u]);

        for(auto& [v,w] : carro[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> c >> p;
    ll a, b, w;
    while(c--){
        cin >> a >> b >> w;
        carro[a].push_back({b,w});
    }
    while(p--){
        cin >> a >> b >> w;
        pe[a].push_back({b,w});
        pe[b].push_back({a,w});
    }

    dijkstraPe(1, peDe1); // menor caminho a pe
    dijkstraPe(n, peParaN); // menor caminho a pe reverso
    ans = peParaN[1];
    dijkstraCarro();
    cout << ans << '\n';

    return 0;
}