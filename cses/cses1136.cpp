/*
    CSES 1136 - Counting Paths
    https://cses.fi/problemset/task/1136
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1, LOG = 19;
vector<int> tree[N], depth(N), cnt(N);
int up[N+1][LOG], n, q, a, b;

void dfs(int no = 1, int p = -1) {
    up[no][0] = p;
    for (int i = 1; i < LOG; ++i) {
        int mid = up[no][i-1];
        up[no][i] = (mid == -1 ? -1 : up[mid][i-1]);
    }

    for (auto &v : tree[no]) {
       if (v == p) continue;
       depth[v] = depth[no]+1;
       dfs(v, no);
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b])
        swap(a,b);
    
    int diff = depth[a] - depth[b];
    for (int i = LOG-1; i >= 0; --i) 
        if (diff & (1 << i)) 
            a = up[a][i];
    
    if (a == b) return a;
    
    for (int i = LOG-1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void cnt_dfs(int no = 1, int p = -1) {
    for (auto &v : tree[no]) {
       if (v == p) continue;
       cnt_dfs(v, no);
       cnt[no] += cnt[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
 
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs();
    while (q--) {
        cin >> a >> b;
        int lca = LCA(a,b);        
        cnt[a]++, cnt[b]++;

        cnt[lca]--;
        if (up[lca][0] != -1)
            cnt[up[lca][0]]--;
    }
    
    cnt_dfs();
    for (int i = 1; i <= n; ++i) 
        cout << cnt[i] << " \n"[i==n];

    return 0;
}