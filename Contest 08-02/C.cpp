#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, t, x;
vector <vector<int>> adj;
vector <int> empregados;

int dfs(int x){
    int total = 0;

    // trabalhador
    if (adj[x].size()==0) return 1;

    for (int i = 0; i < ceil(adj[x].size() * t/100.0); i++)
        total += dfs(adj[x][i]);

    return total;
}

int f(int x){
    int total = 0;

    if (adj[x].size()==0) return empregados[x] = 1;

    for (int i = 0; i < adj[x].size(); i++)
        total += f(adj[x][i]);

    return empregados[x] = total;
}
bool cmp(int a, int b){return empregados[a] < empregados[b];}

int main(){

    while (1){
        cin >> n >> t;
        
        if (!n) break;

        adj.assign(n+1, vector <int> (0));
        empregados.assign(n+1, 0);

        for(int i = 0; i < n; i++){
            cin >> x;
            adj[x].push_back(i+1);
        }
        
        f(0);
        for (auto &v : adj)
            sort(v.begin(), v.end(), cmp);

        // for(int i = 0; i <= n; i++){
        //     if (!adj[i].size()) continue;

        //     fprintf(stderr, "%i: ", i);

        //     for (auto v: adj[i]){
        //         fprintf(stderr, "%i ", v);
        //     }
        //     fprintf(stderr, "\n");
        // }

        // printf("e[1] = %i\n", empregados[1]);

        printf("%i\n", dfs(0));        
    }

    return 0;
}
