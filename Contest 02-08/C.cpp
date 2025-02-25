/*
    Beecrowd 1418 - Outra Crise
    https://judge.beecrowd.com/pt/problems/view/1418
*/

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

    if (adj[x].size()==0){
        empregados[x] = 0;
        return 1;
    }

    for (auto &i : adj[x])
        total += f(i);

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

        fprintf(stderr, "0: ");
        for(int i = 0; i <= adj[0].size(); i++){
            
            fprintf(stderr, "%i ", adj[0][i]);
        }
        fprintf(stderr, " | tam: %i\n", empregados[0]);
        
        for (auto i: adj[0]){
            fprintf(stderr, "%i: ", i);
            for (auto v: adj[i]){
                fprintf(stderr, "%i ", v);
            }
            fprintf(stderr, " | tam: %i\n", empregados[i]);
        }
        
        // printf("e[1] = %i\n", empregados[1]);

        printf("%i\n", dfs(0));        
    }

    return 0;
}
