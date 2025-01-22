#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%i", &n);

    int matriz[n][n], soma;
    bool quadMagico = true;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%i", &matriz[i][j]);

    // Soma do Quadrado Magico
    int somaQuad = 0;
    for (int i = 0; i < n; i++)
        somaQuad += matriz[0][i]; // linha 1

    do{
        // Soma linhas
        for (int i = 0; i < n; i++){
            soma = 0;

            for (int j = 0; j < n; j++)
                soma += matriz[i][j];
            
            if (soma != somaQuad) quadMagico = false;
        }
        
        // Soma colunas
        for (int i = 0; i < n; i++){
            soma = 0;

            for (int j = 0; j < n; j++)
                soma += matriz[j][i];
            
            if (soma != somaQuad) quadMagico = false;
        }

        // Soma coluna principal
        soma = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j) soma += matriz[i][j];
            
        if (soma != somaQuad) quadMagico = false;
            
        // Soma coluna secundaria
        soma = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i + j == n-1) soma += matriz[i][j];
            
        if (soma != somaQuad) quadMagico = false;
        
        break;
    } while (quadMagico == true);

    if (quadMagico) printf("%i\n", somaQuad);
    else printf("-1");

    return 0;
}