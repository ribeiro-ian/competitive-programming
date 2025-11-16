/*
    CSES 1679 - Course Schedule
    https://cses.fi/problemset/task/1679
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
map<int, vector<int>> depth;
vector <vector<int>> graph;
vector<bool> visited;

void dfs(int i, int d) {
    visited[i] = true;
    depth[d].push_back(i);

    for (auto &v : graph[i]) {
        if (!visited[v]) {
            dfs(v, d+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    visited.assign(n+1, false);
    vector <bool> start(n+1, true);

    while (m--) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        start[b] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!start[i]) continue;
        dfs(i, 0);        
    }

    for (auto &[id, v] : depth) {
        for (auto &i : v)
            cout << i << ' ';
    }
    cout << endl;

    return 0;
}