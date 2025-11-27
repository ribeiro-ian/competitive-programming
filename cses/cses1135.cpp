/*
    CSES 1135 - Distance Queries
    https://cses.fi/problemset/task/1135
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1, K = 19;
vector<int> graph[N], depth(N);
int up[N+1][K];
int n, q, a, b;

void dfs(int u = 1, int p = 0) {
    up[u][0] = p;
    for (int i = 1; i < K; i++)
        up[u][i] = up[ up[u][i-1] ][i-1];

    for (auto &v : graph[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
// Find Lowest Common Ancestor with Binary Lifting
int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    // lift a to same depth as b
    int dist = depth[a] - depth[b];
    for (int i = 0; i < K; i++)
        if (dist & (1 << i)) 
            a = up[a][i];

    if (a == b) return dist;
    // lift both until parents match
    for (int i = 0; i < K; i++) {
        if (a != b) {
            dist += 2*(i+1);
            a = up[a][i];
            b = up[b][i];
        }
    }
    if (a==0) dist-=2;
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs();
    while (q--) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}