/*
    CSES 1139 - Distinct Colors
    https://cses.fi/problemset/task/1139
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
vector<int> graph[N], ans(N);
set<int> colors[N];
int n;

void dfs(int u = 1, int p = -1) {

	for (auto& v : graph[u]) {
        if (v == p) continue;
        
        dfs(v, u);
        if (colors[u].size() < colors[v].size()) 
            swap(colors[u], colors[v]);

        for (auto& c : colors[v])
            colors[u].insert(c); 
	}

	ans[u] = colors[u].size();
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        colors[i].insert(x);
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs();

    for (int i = 1; i <= n; ++i) 
        cout << ans[i] << " \n"[i==n];

    return 0;
}