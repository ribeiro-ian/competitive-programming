/*
    Beecrowd 1835 - Promessa de Campanha
    https://judge.beecrowd.com/pt/problems/view/1835
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> adj;
vector <int> visited;

int tc, caso;
int n, m, x, y;

void dfs(int vi, int x){
    
    for (auto a : adj[vi]){
        if (!visited[a]){
            visited[a] = x;
            dfs(a, x);
        }
    }
}

int main(){

    scanf("%i", &tc);
    caso = 0;

    while (tc--){

        scanf("%i %i", &n, &m);
        
        adj.resize(n+1);
        visited.assign(n+1, false);
        for (int i = 0; i < m; i++){
            scanf("%i %i", &x, &y);
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for (int i = 1; i <= n; i++)
            dfs(i, i);
        
        printf("Caso #%i: ", ++caso);

        if (m == 0){
            int ans = n -1;
            if (ans)
                printf("ainda falta(m) %i estrada(s)\n", ans);
            else
                printf("a promessa foi cumprida\n");
        }
        else{
            int qtdZero = count(visited.begin()+1, visited.end(), 0);
            set <int> s;

            for (int i = 1; i <= n; i++)
            {
                if (visited[i])
                    s.insert(visited[i]);
            }

            int ans = s.size() - 1 + qtdZero;
            if (ans)
                printf("ainda falta(m) %i estrada(s)\n", ans);
            else
                printf("a promessa foi cumprida\n");
        }

        adj.clear();
    }
    

    return 0;
}
