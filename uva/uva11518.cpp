/*
    UVA 11518 - Dominos 2
    https://vjudge.net/problem/UVA-11518
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u, int& cnt){
    visited[u] = 1; cnt++;
    
    for(auto& v : graph[u]) 
        if(!visited[v])
            dfs(v, cnt);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int n, m, l;
        cin >> n >> m >> l;
        
        graph.assign(n+1, {});
        visited.assign(n+1, 0);
        while(m--){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }

        int cnt = 0;
        while(l--){
            int src; cin >> src;

            if(!visited[src])
                dfs(src, cnt);
        }
        cout << cnt << '\n';
    }

    return 0;
}