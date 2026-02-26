/*
    CSES 2079 - Finding a Centroid
    https://cses.fi/problemset/task/2079
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
vector<int> graph[N], subtree_size(N, 1);
int n;

void dfs(int u = 1, int p = -1) {
    for (auto& v : graph[u]) {
        if (v == p) continue;

        dfs(v,u);
        subtree_size[u] += subtree_size[v];
    }
}

int get_centroid(int u = 1, int p = -1) {
	for (auto& v : graph[u]) {
		if (v == p) { continue; }

        if (subtree_size[v] * 2 > n)
            return get_centroid(v, u);
	}

	return u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs();
    cout << get_centroid() << '\n';
    
    return 0;
}