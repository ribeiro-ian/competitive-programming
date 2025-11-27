/*
    CSES 1680 - Longest Flight Route
    https://cses.fi/problemset/task/1680
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+1;
int n, m;
vector <vector<int>> graph(MAXN);
vector <int> in_degree(MAXN, 0), child(MAXN, 0);
vector<bool> visited(MAXN, false);
queue <int> q;

void dfs(int i = 1) {
    visited[i] = true;
    
    for (auto &v : graph[i]) {
        in_degree[v]++;
        if (!visited[v])
            dfs(v);
    }
}

void bfs() {
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto &v : graph[u]) {
            in_degree[v]--;

            if (!in_degree[v]) {
                child[v] = u;
                q.push(v);
            }
        }
    }
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
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) continue;
            if (!in_degree[i]) {
                q.push(i);
                child[i] = -1;
            }
        }
        
        bfs();
        vector<int> path;
        for (int i = n;; i = child[i]) {
            if (i==-1) break;
            path.push_back(i);
        }
        reverse(path.begin(), path.end());

        cout << (int)path.size() << '\n';
        for (auto &i : path) 
           cout << i << ' ';
        cout << endl;
    }

    return 0;
}