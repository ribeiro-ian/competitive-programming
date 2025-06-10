/*
    Beecrowd 1835 - Promessa de Campanha
    https://judge.beecrowd.com/pt/problems/view/1835
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <bool> visited;

void dfs(int no) {
    visited[no] = true;
    
    for (auto v : adj[no]) {
        if (!visited[v]) 
            dfs(v);
    }
}

int main() {
    int tc, caso = 0;
    int n, m, a, b;
    
    scanf("%i", &tc);

    while (tc--) {
        scanf("%i %i", &n, &m);
        
        adj.resize(n+1);
        visited.assign(n+1, false);

        for (int i = 0; i < m; i++) {
            scanf("%i %i", &a, &b);
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int cnt = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }

        printf("Caso #%i: ", ++caso);
        if (cnt)
            printf("ainda falta(m) %i estrada(s)\n", cnt);
        else
            printf("a promessa foi cumprida\n");

        adj.clear();
    }

    return 0;
}
