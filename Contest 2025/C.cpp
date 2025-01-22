#include <bits/stdc++.h>
using namespace std;

void ehQuad(int soma, int somaQuad){
    if (soma != somaQuad){
        printf("-1\n");
        exit(0);
    }
}

int main(){
    int n; cin >> n;

    int matriz[n][n], soma;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matriz[i][j];

    // Soma do Quadrado Magico
    int somaQuad = 0;
    for (int i = 0; i < n; i++)
        somaQuad += matriz[0][i]; // linha 1

    // Soma linhas
    for (int i = 0; i < n; i++){
        soma = 0;

        for (int j = 0; j < n; j++)
            soma += matriz[i][j];
        
        ehQuad(soma, somaQuad);
    }
    
    // Soma colunas
    for (int i = 0; i < n; i++){
        soma = 0;

        for (int j = 0; j < n; j++)
            soma += matriz[j][i];
        
        ehQuad(soma, somaQuad);
    }

    // Soma coluna principal
    soma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j) soma += matriz[i][j];
        
    ehQuad(soma, somaQuad);
        
    // Soma coluna secundaria
    soma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j == n-1) soma += matriz[i][j];
        
    ehQuad(soma, somaQuad);
        

    printf("%i\n", somaQuad);

    return 0;
}