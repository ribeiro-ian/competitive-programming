/*
    CSES 1681 - Game Routes
    https://cses.fi/problemset/task/1681
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int M = 1e9+7, N = 1e5+1;
int n, m;
vector <int> graph[N];
vector<int> in_degree(N), ways(N);
vector<bool> visited(N,false);

void self_add(int &x, int y = 1) {
    x = (x + y) % M;
}

void dfs(int i = 1) {
    visited[i] = true;
    for (auto &v : graph[i]) {
        self_add(in_degree[v]);
        if (!visited[v])
            dfs(v);
    }
}

int bfs(int src = 1) {
    queue <int> q;
    q.push(src);
    ways[src] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto &v : graph[u]) {
            in_degree[v]--;
            self_add(ways[v], ways[u]);
            
            if (!in_degree[v]) {
                q.push(v);
            }
        }
    }
    return ways[n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs();
    cout << bfs() << '\n';

    return 0;
}