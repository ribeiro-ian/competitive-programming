/*
    CSES 1674 - Subordinates
    https://cses.fi/problemset/task/1674
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> graph;
vector <int> emp;
vector <bool> visited;

int dfs(int no) {
    visited[no] = true;

    for (auto &child : graph[no])
        if (!visited[child])
            emp[no] += dfs(child);
    
    return emp[no] + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    graph.resize(n+1);
    emp.assign(n+1, 0);
    visited.assign(n+1, false);

    for (int i = 2; i <= n; ++i) {
        int parent; cin >> parent;
        graph[parent].push_back(i);
        graph[i].push_back(parent);
    }
    
    dfs(1);
    for (int i = 1; i <= n; ++i) 
        cout << emp[i] << ' ';
    cout << '\n';
    
    return 0;
}