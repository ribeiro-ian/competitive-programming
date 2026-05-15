/*
    Maratona Mineira 2025 - E - Emparelhamento
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
<<<<<<< Updated upstream
using ull = unsigned long long;

vector <vector <ll>> adj;
vector <bool> visited;
=======

const ll N = 2e5+1;
vector <ll> adj[N];
vector <bool> visited(N, false);
>>>>>>> Stashed changes
ll cnt;

void dfs(ll u){
    visited[u] = true;
    cnt++;
    
<<<<<<< Updated upstream
    for(auto &v : adj[u]){
        if(!visited[v])
=======
    for (auto &v : adj[u])
        if (!visited[v])
>>>>>>> Stashed changes
            dfs(v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

<<<<<<< Updated upstream
    ll n, a, b; cin >> n;
    adj.resize(n+1);
    visited.assign(n+1, false);

    for(ll i = 0; i < n; ++i){
=======
    ll n, a, b;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
>>>>>>> Stashed changes
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            ans += cnt - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}