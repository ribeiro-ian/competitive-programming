/*
    CSES 1130 - Tree Matching
    https://cses.fi/problemset/task/1130
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<int>> graph;
vector <bool> visited;
int n, ans = 0;

bool dfs(int i, int p) {
    visited[i] = true;
    if (graph[i].size() == 1)
        return true;
    
    bool flag = false;
    for (auto &v : graph[i]) {
        if (v==p) continue;

        if (!visited[v]) {
            if (dfs(v, i)) {
                if (!flag) {
                    // cerr << "( " << i << ", " << v << " )\n";
                    flag = true;
                    ans++;
                }
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    graph.resize(n+1);
    visited.assign(n+1,false);
    for (int a, b, i = 0; i < n-1; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    cout << ans << '\n';

    return 0;
}