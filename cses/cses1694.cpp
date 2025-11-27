/*
    CSES 1694 - Download Speed
    https://cses.fi/problemset/task/1694
*/
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<ll,ll>;
 
const int N = 501;
int n, m;
ll graph[N][N], back[N][N];
vector<int> vis(N);
ll threshold = 0, INF = 1e18;
bool flag = false;
 
ll dfs(int u, ll flow) {
    if (u==n) {
        flag = true;
        return flow;
    }
    vis[u] = true;
 
    for (int v = 1; v <= n; ++v) {
        auto w = graph[u][v];
 
        if (w >= threshold && !vis[v]) {
            ll cost = dfs(v, min(flow, w));
 
            graph[u][v] -= cost;
            back[v][u] += cost;
        }
    }

    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
 
    memset(graph, 0, sizeof(graph));
    memset(back, 0, sizeof(back));
 
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
 
        graph[a][b] = c;
        threshold += c;
    }
 
    while (threshold >= 1) {
        flag = false;
        dfs(1, INF);
        if (!flag) threshold /= 2;
    }
 
    ll ans = 0;
    for (int i = 1; i <= n; ++i) 
        ans += back[n][i];
    
    cout << ans << '\n';
 
    return 0;
}