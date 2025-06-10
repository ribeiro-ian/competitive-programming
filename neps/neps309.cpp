/*
    Neps 309 - Gincana (OBI 2011)
    https://neps.academy/br/exercise/309
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;

void dfs(int no) {
    visited[no] = true;

    for (auto &v : adj[no]) 
        if (!visited[v])
            dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    
    adj.assign(n+1, vector <int>());
    visited.assign(n+1, false);

    while (m--) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}