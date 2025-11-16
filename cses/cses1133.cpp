/*
    CSES 1133 - Tree Distances II
    https://cses.fi/problemset/task/1133
*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll N = 2e5+1;
ll n;
vector<ll> graph[N], ans(N), subSize(N, 1);

void dfs2(ll i = 1, ll p = 0) {
	for (auto &v : graph[i]) {
        if (v == p) continue;

        ans[v] = ans[i] + n - 2 * subSize[v];
        dfs2(v, i);
    }

}

void dfs1(ll i = 1, ll p = 0, ll depth = 0) {
    ans[1] += depth;
	for (auto &v : graph[i]) {
        if (v == p) continue;
        
        dfs1(v, i, depth+1);
        subSize[i] += subSize[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
 
    for (ll i = 1; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs1();
    dfs2();
 
    for (ll i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i==n];
 
    return 0;
}