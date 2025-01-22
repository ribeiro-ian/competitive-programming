#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <bool> visited;
vector <vector <int>> adj;

void dfs(int vi){
    visited[vi] = true;
    
    for (auto &a : adj[vi])
        if (!visited[a])
            dfs(a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    visited.resize(n);
    adj.resize(n);

    vector <pair <int, int>> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            // dist entre dois pontos             
            if (sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2)) <= d){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]){
            dfs(i);
            cnt++;
        }
    }

    cout << (cnt == 1 ? "S" : "N") << "\n";
    
    return 0;
}
