/*
    CSES 1666 - Building Roads
    https://cses.fi/problemset/task/1666
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <bool> visited;

void dfs(int no){
    visited[no] = true;
    for (auto &v : adj[no]) 
        if (!visited[v])
            dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.assign(n+1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int cnt = 0;
    vector <int> ans;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt-1 << '\n';

    for (int i = 0; i < ans.size()-1; i++) 
        cout << ans[i] << ' ' << ans[i+1] << '\n';

    return 0;
}