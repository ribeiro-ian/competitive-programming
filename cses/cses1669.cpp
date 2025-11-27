/*
    CSES 1669 - Round Trip
    https://cses.fi/problemset/task/1669
*/
 
#include <bits/stdc++.h>
using namespace std;
 
int n, m, x;
vector <vector<int>> graph;
vector <bool> visited;
vector <int> cycle;
 
bool dfs(int i, int p) {
    if (visited[i]) {
        if (cycle.empty()) {
            cycle.push_back(i);
            return true;
        }
        return false;
    }
 
    visited[i] = true;
    for (auto &v : graph[i]) {
        if (v == p) continue;
        if (dfs(v, i)) {
            cycle.push_back(i);
 
            if (i == cycle.front()) return false;
            return true;
        }
    }
 
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    graph.resize(n+1);
    visited.assign(n+1, false);
    while(m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i){
        if (visited[i]) continue;
        dfs(i, -1);
        
        if (cycle.size() > 2) {
            cout << (int)cycle.size() << "\n";
            for (auto &e : cycle)
                cout << e << " ";
            cout << "\n";
 
            return 0;
        }
        cycle.clear();
    }
    cout << "IMPOSSIBLE\n";
 
    return 0;
}