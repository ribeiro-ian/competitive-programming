/*
    Neps 520 - Tarzan
    https://neps.academy/br/exercise/520
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <bool> visited;

void dfs(int no) {
    visited[no] = true;
    
    for (auto &v : adj[no])
        if (!visited[v])
            dfs(v);
}

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;

    adj.assign(n, vector <int>());
    visited.assign(n, false);

    vector <pair <int, int>> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // dist entre dois pontos             
            if (sqrt( pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2) ) <= d) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << (cnt == 1 ? 'S' : 'N') << '\n';
    
    return 0;
}