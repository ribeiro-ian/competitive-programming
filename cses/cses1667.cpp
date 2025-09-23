/*
    CSES 1667 - Message Route
    https://cses.fi/problemset/task/1667
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;

void bfs(int no) {
    queue <int> q;
    visited[no] = no;
    q.push(no);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto &v : adj[curr]) {
            if (!visited[v]) {
                visited[v] = curr;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    
    adj.assign(n+1, vector <int>());
    visited.assign(n+1, 0);

    while (m--) {
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
        
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    int i = n, cnt = 1;
    stack <int> ans;
    ans.push(n);

    while (visited[i] != i) {
        ans.push(visited[i]);
        i = visited[i];
        cnt++;
    }

    cout << cnt << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';

    return 0;
}