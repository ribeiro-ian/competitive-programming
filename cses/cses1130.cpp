/*
    CSES 1130 - Tree Matching
    https://cses.fi/problemset/task/1130
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2*1e5+1;
vector<int> graph[N];
vector<bool> visited(N,false);
int cnt = 0;

void dfs(int i, int p) {
    for (auto &v : graph[i]) {
        if (v==p) continue;

        dfs(v, i);
        if (!visited[i] && !visited[v]) {
            visited[i] = visited[v] = true;
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);

    cout << cnt << '\n';

    return 0;
}