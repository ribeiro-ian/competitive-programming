/*
    CSES 1668 - Building Teams
    https://cses.fi/problemset/task/1668
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
vector <vector<int>> adj;
vector <bool> visited;
vector <int> team;
bool flag = true;

int alt(int i) {
    return (i==1 ? 2 : 1);
}

void dfs(int no, int t) {
    if (visited[no]) return;
    visited[no] = true;
    team[no] = t;

    for (auto &v : adj[no]) {
        if (!visited[v]) dfs(v, alt(t));
        else {
            if (team[v] == team[no]) {
                flag = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adj.resize(n+1);
    team.assign(n+1, 0);
    visited.assign(n+1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 1);
        }
        if (!flag) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }


    for (int i = 1; i <= n; ++i)
        cout << team[i] << ' ';
    cout << '\n';


    return 0;
}