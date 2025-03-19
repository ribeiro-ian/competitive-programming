#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> adj;
vector <bool> visited;

void bfs(int no) {
    queue <int> fila;
    
    visited[no] = true;
    fila.push(no);
    
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        
        for (auto v : adj[atual]) {
            if (!visited[v]) {
                fila.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%i%i", &n, &m);
    adj.assign(n+1, vector<int> ());
    visited.assign(n+1, false);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%i%i", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            cnt++;
        }
    }

    printf("%i\n", cnt);

    return 0;
}