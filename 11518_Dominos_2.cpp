#include <bits/stdc++.h>
using namespace std;

int tc, n, m, l, x, y, cnt;
vector <vector <int>> adj;
vector <bool> visited;

void dfs(int vi){
    if (visited[vi])
        return;
    
    visited[vi] = true;

    for (auto &a : adj[vi]){
        if (!visited[a]){
            dfs(a);
        }
    }
}

int main(){
    cin >> tc;

    while (tc--){
        visited.clear();
        for (auto &a : adj)
            a.clear();

        cin >> n >> m >> l;

        visited.resize(n+1);
        adj.resize(n+1);
        
        for (int i = 0; i < m; i++){
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 0; i < l; i++){
            cin >> x;
            dfs(x);
        }

        cnt = 0;
        for (int i = 1; i <= n; i++)
            if (visited[i]) cnt++;
        
        cout << cnt << endl;
    }

    return 0;
}
