/*
    CSES 1132 - Tree Distances I
    https://cses.fi/problemset/task/1132
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+1;
vector<int> graph[N], to(N), maxd1(N), maxd2(N);
 
void dfs2(int i, int p) {
    for (auto &v : graph[i]) {
        if (v == p) continue;
        
        int dist;
        if (to[i] == v)
            dist = maxd2[i] + 1;
        else 
            dist = maxd1[i] + 1;

        // Update v's distances
        if (dist > maxd1[v]) {
            maxd2[v] = maxd1[v];
            maxd1[v] = dist;
            to[v] = i;
        }
        else if (dist > maxd2[v]) 
            maxd2[v] = dist;
        
        dfs2(v, i);
    }
}
 
void dfs1(int i, int p) {
    for (auto &v : graph[i]) {
        if (v == p) continue;
        dfs1(v,i);
 
        if (maxd1[v]+1 > maxd1[i]) {
            maxd2[i] = maxd1[i];
            maxd1[i] = maxd1[v]+1;
            to[i] = v;
        }
        else if (maxd1[v]+1 > maxd2[i]) {
            maxd2[i] = maxd1[v]+1;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
 
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs1(1, -1);
    dfs2(1, -1);
 
    for (int i = 1; i <= n; ++i)
        cout << maxd1[i] << " \n"[i==n];
 
    return 0;
}