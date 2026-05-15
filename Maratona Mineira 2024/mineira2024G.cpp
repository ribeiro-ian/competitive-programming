/*
    Maratona Mineira 2024 - G - Passaporte
    https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/G
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // dist[node][cost] = min voos para chegar em node gastando exatamente cost
    const int INF = 1e9;
    vector<vector<int>> dist(n+1, vector<int>(k+1, INF));

    // {no, custo_acumulado}
    queue<pair<int,int>> q;
    dist[1][0] = 0;
    q.push({1, 0});

    while (!q.empty()) {
        auto [u, custo] = q.front(); q.pop();

        for (auto& [v, w] : graph[u]) {
            int novo_custo = custo + w;
            if (novo_custo > k) continue;
            if (dist[v][novo_custo] > dist[u][custo] + 1) {
                dist[v][novo_custo] = dist[u][custo] + 1;
                q.push({v, novo_custo});
            }
        }
    }

    int ans = INF;
    for (int c = 0; c <= k; c++)
        ans = min(ans, dist[n][c]);

    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}