/*
    OBI 2025 - Fase 2 - Mania de Ímpar
    https://neps.academy/br/exercise/3267
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int grid[101][101], n, m;

bool condition(int i, int j, int parity) {
    int sum = i+j;
    return (sum % 2 == 0 && grid[i][j] % 2 != parity) || (sum % 2 == 1 && grid[i][j] % 2 == parity);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> grid[i][j];
    
    int parity = grid[0][0] % 2, cnt = 0;

    /* 
        Caso 1: Incrementar em todas posições pares do xadrez de valor
        com paridade != grid[0][0] OU Todas as posições impares de valor
        com paridade == grid[0][0].

        Caso 2: Se o caso 1 acabar alterando mais valores do que deixando
        valores passar, a melhor opção é alterar os valores que NÃO enquadram
        o caso 1.
    */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i+j) % 2 == 0 && grid[i][j] % 2 != parity) 
                cnt++;
            if ((i+j) % 2 == 1 && grid[i][j] % 2 == parity)
                cnt++;
        }
    }

    if (cnt <= n*m-cnt) {
        cout << cnt << '\n';

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (condition(i, j, parity))
                   grid[i][j]++;

                cout << grid[i][j] << " \n"[j==m-1];
            }
        }
    }
    else {
        cout << n*m-cnt << '\n';

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!condition(i, j, parity))
                    grid[i][j]++;
                cout << grid[i][j] << " \n"[j==m-1];
            }
        }
    }
        
    return 0;
}