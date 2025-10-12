/*
    CSES 1669 - 
    https://cses.fi/problemset/task/1669
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<int>> graph;
vector <bool> visited;
vector <int> ans;
int n, m;

bool dfs(int no, int p) {
    visited[no] = true;

    for (auto &v : graph[no]) {
        if (v==p) continue;

        if (!visited[v])
            if (dfs(v, no)) {
                ans.push_back(no);
                return true;
            }
        else {
            cerr << "stop at " << no << " => " << v << endl;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    visited.assign(n+1, false);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool flag = false;
    for (int i = 1; i <= n;++i) {
        if (!visited[i]) {
            cerr << i << '\n';
            flag = dfs(i, -1);
            if (flag) break;
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    ans.push_back(ans.front());
    cout << (int) ans.size() << '\n';        
    for (auto &i : ans) 
        cout << i << ' '; cout << endl;
    

    return 0;
}