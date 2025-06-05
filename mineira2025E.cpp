/*
    Maratona Mineira 2025E - Emparelhamento
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <ll>> adj;
vector <bool> visited;
ll cnt;

void dfs(ll u) {
    visited[u] = true;
    cnt++;
    
    for (auto &v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, a, b; cin >> n;
    adj.resize(n+1);
    visited.assign(n+1, false);

    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cnt = 0;
            dfs(i);
            ans += cnt - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}