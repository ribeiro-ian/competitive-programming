/*
    Codeforces 839C - Journey
    https://codeforces.com/contest/839/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

vector<vector<int>> graph;
vector<bool> visited;

ld dfs(int no) {
    visited[no] = true;
    if (graph[no].size() == 1) return 0.;
    
    ld sum = 0.;
    for (auto &v : graph[no]) {
        if (!visited[v]) sum += dfs(v)+1;
    }

    return sum/(graph[no].size() - (no != 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    graph.resize(n+1);
    visited.assign(n+1, false);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    cout << fixed << setprecision(7) << dfs(1) << '\n';


    return 0;
}