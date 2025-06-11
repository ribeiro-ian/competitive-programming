/*
    Bee 2067 - Jogo do Quadrado
    https://judge.beecrowd.com/pt/problems/view/2067
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n, m, q, x;
    scanf("%i %i", &n, &m);
    cin >> n >> m;
    
    int grid[n][m];
    int pref[n+1][m+1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%i %i", &grid[i][j]);
            if (grid[i][j] == 0) pref[i+1][j+1] = 0;
            else pref[i+1][j+1] =
        }

    while(q--)
    {
        cin >> x;


    }

    
    

    return 0;
}
