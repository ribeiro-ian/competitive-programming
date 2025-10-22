/*
    CSES 1683 - Planets and Kingdoms
    https://cses.fi/problemset/task/1683
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector <int> graph1[N], graph2[N];
vector<int> vis(N, false), comp(N);
vector<int> order;

void dfs1(int no) {
    vis[no] = true;
    for (auto &v : graph1[no])
        if (!vis[v])
            dfs1(v);

    order.push_back(no);
}

void dfs2(int no, int c) {
	vis[no] = true;
	for (auto &v : graph2[no])
		if (!vis[v])
            dfs2(v, c);

	comp[no] = c;
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs1(i);
    
    vis.assign(N, false);
    reverse(order.begin(), order.end());

    int comps = 0;
    for (auto &i : order)
        if (!vis[i])
            dfs2(i, ++comps);

    cout << comps << '\n';
    for (int i = 1; i <= n; ++i)
        cout << comp[i] << " \n"[i==n];

    return 0;
}