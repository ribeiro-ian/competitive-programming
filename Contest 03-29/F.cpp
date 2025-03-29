#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;
int n, l, a, b;

bool bfs(int no){
    queue <int> q;
    int cnt = 0;
    
    q.push(no);
    visited[no] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto &v : adj[curr]){
            if (visited[v] == -1) {
                visited[v] = visited[curr]+1;
                q.push(v);
            }
            else if (visited[v] == visited[curr]){
                return false;
            }
        }

        cnt++;
    }

    return true;
}

int main() {

    while (scanf("%i", &n), n){
        adj.assign(n, vector <int> ());
        visited.assign(n, -1);

        scanf("%i", &l);
        while (l--) {
            scanf("%i %i", &a, &b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // for (int i = 0; i < n; i++) {
        //     printf("%2i: %lu\n", i, adj[i].size());
        // }
        
        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            if (visited[i] == -1)
                flag = bfs(i);
        }

        printf("%s.\n", flag ? "BICOLORABLE" : "NOT BICOLORABLE");

    }

    return 0;
}