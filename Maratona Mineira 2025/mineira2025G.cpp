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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void dijkstraPe(int s, vector<ll>& d){
=======
void dijkstra(int s, vector<ll>& d){
>>>>>>> Stashed changes
=======
void dijkstra(int s, vector<ll>& d){
>>>>>>> Stashed changes
    d.assign(n+1, INF);
    priority_queue<pair<ll,ll>> pq;
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
<<<<<<< Updated upstream
<<<<<<< Updated upstream
        auto [du, u] = pq.top();
        pq.pop();
        if(-du > d[u]) continue;
        
=======
        auto [_, u] = pq.top();
        pq.pop();

>>>>>>> Stashed changes
=======
        auto [_, u] = pq.top();
        pq.pop();

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
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

=======
=======
>>>>>>> Stashed changes
        dist[i] = peDe1[i];
        pq.push({-dist[i], i});
    }

    while(!pq.empty()){
        auto [_, u] = pq.top();
        pq.pop();

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
        for(auto& [v,w] : carro[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
            }
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
            if(peParaN[v] != INF)
                ans = min(ans, dist[v]+peParaN[v]);
>>>>>>> Stashed changes
=======
            if(peParaN[v] != INF)
                ans = min(ans, dist[v]+peParaN[v]);
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
    dijkstraPe(1, peDe1); // menor caminho a pe
    dijkstraPe(n, peParaN); // menor caminho a pe reverso
=======
    dijkstra(1, peDe1);
    dijkstra(n, peParaN);
>>>>>>> Stashed changes
=======
    dijkstra(1, peDe1);
    dijkstra(n, peParaN);
>>>>>>> Stashed changes
    ans = peParaN[1];
    dijkstraCarro();
    cout << ans << '\n';

    return 0;
}