/*
    SPOJ - A Bug’s Life
    https://www.spoj.com/problems/BUGLIFE/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> prof;

bool bfs(int no) {
    queue<int> q;

    prof[no] = 0;
    q.push(no);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto &v : adj[curr]) {
            if (prof[v] == -1) {
                prof[v] = prof[curr]+1;
                q.push(v);
            }
            else if (prof[curr] == prof[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, n, m, a, b, cnt = 1;

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        adj.assign(n+1, vector<int>());
        prof.assign(n+1, -1);
        
        while (m--) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool flag = true;
        for (int i = 1; i <= n && flag; i++) {
            if (prof[i] == -1)
                flag = bfs(i);
        }

        printf("Scenario #%i:\n", cnt++);
        cout << (!flag ? "Suspicious bugs found!" : "No suspicious bugs found!") << '\n';
    }

    return 0;
}