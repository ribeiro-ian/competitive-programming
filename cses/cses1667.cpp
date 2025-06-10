/*
    CSES 1667 - Message Route
    https://cses.fi/problemset/task/1667
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;

void bfs(int no) {
    queue <int> q;
    visited[no] = no;
    q.push(no);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto &v : adj[curr]) 
            if (!visited[v]) {
                visited[v] = curr;
                q.push(v);
            }
    }
}

int main() {
    int n, m, a, b;
    scanf("%i %i", &n, &m);
    
    adj.assign(n+1, vector <int>());
    visited.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        scanf("%i %i", &a, &b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
   
    if (!visited[n]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    
    int i = n, cnt = 1;
    stack <int> ans;
    ans.push(n);

    while (visited[i] != i) {
        ans.push(visited[i]);
        i = visited[i];
        cnt++;
    }

    printf("%i\n", cnt);
    
    while (!ans.empty()) {
        printf("%i ", ans.top());
        ans.pop();
    }
    printf("\n");

    return 0;
}