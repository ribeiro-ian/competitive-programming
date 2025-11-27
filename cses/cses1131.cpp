/*
    CSES 1131 - Tree Diameter
    https://cses.fi/problemset/task/1131
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> graph;
vector<int> len;
vector<bool> visited;
int ans = 0;

int dfs(int no) {
    visited[no] = true;

    if (graph[no].size() == 1) return len[no] = 0;
    
    priority_queue<int> dist;
    for (auto &v : graph[no]) {
        if (!visited[v]) {
            dist.push(dfs(v)+1);
        }
        else dist.push(len[v]+1);
    }
    int max_len = dist.top();
    dist.pop();
    cerr << "No " << no << " = " << max_len;

    if (!dist.empty()) {
        ans = max(ans, max_len + dist.top());
        cerr << " + " << dist.top();
    }
    cerr << endl;

    return len[no] = max_len;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    graph.resize(n+1);
    len.assign(n+1, 0);
    visited.assign(n+1, false);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (n <= 3) {
        cout << n-1 << '\n';
        return 0;
    }
    
    for (int i = 1; i < n+1; ++i) {
        if (!visited[i]) {
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << endl;

    return 0;
}