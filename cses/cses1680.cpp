/*
    CSES 1680 - Longest Flight Route
    https://cses.fi/problemset/task/1680
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+1;
int n, m;
vector <vector<int>> graph(MAXN);
vector <int> in_degree(MAXN, 0), dist(MAXN, 0), child(MAXN, 0);
queue <int> q;

vector<bool> visited(MAXN, false);
vector<int> ans;

void dfs(int i = 1) {
    visited[i] = true;

    for (int v : graph[i]) 
        if (!visited[v]) dfs(v);
}

void bfs(int src = 1) {
    dist[src] = 0;
    child[src] = src;
    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        int d = dist[u]+1;
        for (auto &v : graph[u]) {
            in_degree[v]--;
            
            if (!in_degree[v]) {
                if (visited[v]) child[v] = u;
                dist[v] = d;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }


    
    dfs();
    cerr << "Visitados:\n";
    for (int i = 1; i <= n; ++i)
        cerr << i << ": " << visited[i] << endl;
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int i = 1; i <= n; ++i) if (!in_degree[i]) q.push(i);
        bfs();

        cerr << "Childs:\n";
        for (int i = 1; i <= n; ++i) 
            cerr << i << " : " << child[i] << endl;
        

        // for (int i = n;; i = child[i]) {
        //     ans.push_back(i);
        //     if (i==1) break;
        // }
        // reverse(ans.begin(), ans.end());
        // cout << (int)ans.size() << '\n';
        // for (auto &i : ans) 
        //    cout << i << ' ';
        // cout << endl;
    }

    return 0;
}