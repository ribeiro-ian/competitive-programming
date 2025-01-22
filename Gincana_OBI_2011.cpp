#include <bits/stdc++.h>
using namespace std;
/*
vector <bool> visited;
vector <vector <int>> v;

void dfs(int vi){
    visited[vi] = true;

    for (auto &a : v[vi])
        if (!visited[a])
            dfs(a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    
    v.resize(n+1);
    visited.resize(n+1);
    for (int i = 0; i < m; i++){
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    
    printf("%i\n", cnt);

    return 0;
}
*/

const int MAX = 1001;
int parent[MAX];

int root(int x){
    if (parent[x] == x) return x;

    return parent[x] = root(parent[x]);    
}
void join(int x, int y){
	parent[root(x)] = root(y);
}

void connectedComponents(int n){
    set<int> s;

    for (int i = 1; i <= n; i++) 
        s.insert(root(i));

    cout << s.size() << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++){
        cin >> x >> y;

        join(x, y);
    }

    connectedComponents(n);

    return 0;
}
