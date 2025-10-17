/*
    CSES 1678 - Round Trip II
    https://cses.fi/problemset/task/1678
*/
 
#include <bits/stdc++.h>
using namespace std;
 
int n, m, x;
vector <vector<int>> graph;
vector <bool> visited;
vector <int> cycle;
bool found = false;

void printCycle(int st) {
    found = true;
    vector <int> ans = {st};

    for (int i = cycle.size()-1; i >= 0; --i) {
        ans.push_back(cycle[i]);
        if (cycle[i] == st) break;
    }

    cout << (int)ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << '\n';
}

void dfs(int i) {
    if (found) return;
    if (visited[i]) {
        if (cycle.size() > 1) 
            printCycle(i);
        return;
    }
 
    visited[i] = true;
    cycle.push_back(i);
    bool flag = false;
    for (auto &v : graph[i]) {
        if (!graph[v].size()) continue;
        flag = true;
        dfs(v);
    }
    visited[i] = flag;

    cycle.pop_back();
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
    }
 
    for (int i = 1; i <= n; ++i){
        if (visited[i] || found) continue;
        dfs(i);
        cycle.clear();
    }
    if (!found)
        cout << "IMPOSSIBLE\n";
 
    return 0;
}