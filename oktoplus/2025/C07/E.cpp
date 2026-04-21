/*
    CSES 1666 - Building Roads
    https://cses.fi/problemset/task/1666
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;
int cnt;

void dfs(int no){
    visited[no] = cnt;

    for (auto &v : adj[no]) {
        if (visited[v] == -1)
            dfs(v);
    }
}

int main() {
    int n, m, a, b;
    scanf("%i%i", &n, &m);

    adj.resize(n+1);
    visited.assign(n+1, -1);

    for (int i = 0; i < m; i++) {
        scanf("%i%i", &a, &b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cnt = 0;

    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            dfs(i);
            cnt++;
            ans.push_back(i);
        }
    }
    printf("%i\n", cnt-1);

    for (int i = 0; i < ans.size()-1; i++) {
        printf("%i %i\n", ans[i], ans[i+1]);
    }

    return 0;
}