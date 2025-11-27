/*
    CSES 1679 - Course Schedule
    https://cses.fi/problemset/task/1679
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+1;
int n, m;
vector <vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false), processing(MAXN, false);
vector<int> ans;
bool hasCycle = false;

void dfs(int i) {
    visited[i] = true;
    processing[i] = true;

    for (int v : graph[i]) {
        if (!visited[v]) {
            dfs(v);
        }
        else if (processing[v]) {
            hasCycle = true;
            return;
        }
    }
    processing[i] = false;

    ans.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) 
        if (!visited[i]) 
            dfs(i);

    if (hasCycle) 
        cout << "IMPOSSIBLE\n";
    else {
        reverse(ans.begin(), ans.end());
        for (auto &i : ans) 
           cout << i << ' ';
        cout << endl;
    }

    return 0;
}