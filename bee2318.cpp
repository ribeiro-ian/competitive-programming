#include <stdio.h>

#define TAM 3

int buscarSoma(int tam, int m[][tam]);
void completarZeros(int tam, int m[][tam], int soma);
int contarZeros(int tam, int linha, int m[][tam]);

int main(){
    int matriz[TAM][TAM];

    // Input Quadrado Mágico
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            scanf("%i", &matriz[i][j]);
    
    // Procurar o valor da soma do quadrado.
    int somaQuad = buscarSoma(TAM, matriz);
    
    // Substituir casos do valor 0 pelo valor restante.
    completarZeros(TAM, matriz, somaQuad);

    // Print Quadrado Mágico completo.
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (j == TAM -1)
                printf("%i\n", matriz[i][j]);
            else
                printf("%i ", matriz[i][j]);
        }
    }

    return 0;
}

/*
Busca valor da soma do quadrado.
Entrada: tamanho da matriz e a propria matriz.
Saida: valor da soma do quadrado.
*/ 
int buscarSoma(int tam, int m[][tam]){
    int soma = 0;

    // Linhas
    for (int lin = 0; lin < tam; lin++){
        for (int col = 0; col < tam; col++){
            soma += (m[lin][col]);
            
            if (m[lin][col] == 0){
                soma = 0;
                break;
            }
        }
        
        if (soma)
            return soma;
    }

    // Colunas
    for (int col = 0; col < tam; col++){
        for (int lin = 0; lin < tam; lin++){
            soma += (m[lin][col]);

            if (m[lin][col] == 0){
                soma = 0;
                break;
            }
        }
        
        if (soma)
            return soma;
    }

    /*
    Se até aqui não foi encontrado o valor da soma do quadrado mágico,
    só resta ser a soma da diagonal principal ou secundária
    ou em ultimo caso a soma de todos elementos dividido por 2
    */

    // Diagonal Principal
    if (soma == 0)
        for (int i = 0; i < tam; i++){
            soma += m[i][i];
            
            if (m[i][i] == 0){
                soma = 0;
                break;
            }
        }
    if (soma)
        return soma;
    
    // Diagonal Secundaria
    if (soma == 0)
        for (int lin = tam-1, col = 0; col < tam; lin--, col++){
            soma += m[lin][col];    
         
            if (m[lin][col] == 0){
                soma = 0;
                break;
            }
        }
    if (soma)
        return soma;
    
    // Ultimo caso
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            soma += m[i][j];
    soma /= 2;

    return soma;
}

/*
Substitui as instancias do valor 0 pelo valor necessario parar forma o quadrado mágico.
Entrada: tamanho da matriz, a propria matriz e o valor encontrado da soma do quadrado.
Saida: nenhuma.
*/
void completarZeros(int tam, int m[][tam], int somaQuad){
    // Linhas
    for (int lin = 0; lin < tam; lin++){
        
        if(contarZeros(tam, lin, m) > 1)
            continue;
                
        for (int col = 0; col < tam; col++)
            
            if (m[lin][col] == 0){
                int soma = 0;
                
                // Soma os valores da linha.
                for (int aux = 0; aux < tam; aux++)
                    soma += m[lin][aux];
                
                // Completa o valor 0 com o restante para a soma do quadrado.
                m[lin][col] = somaQuad - soma;
            }
    }

    // Colunas
    for (int col = 0; col < tam; col++){                
        for (int lin = 0; lin < tam; lin++)
            
            if (m[lin][col] == 0){
                int soma = 0;
                
                // Soma os valores da coluna.
                for (int aux = 0; aux < tam; aux++)
                    soma += m[aux][col];
                
                // Completa o valor 0 com o restante para a soma do quadrado.
                m[lin][col] = somaQuad - soma;
            }
    }
}

/*
Conta a qntd de 0 na linha passada.
Entrada: tamanho da matriz, linha da matriz e a propria matriz.
Saida: Quantidade de zeros.
*/
int contarZeros(int tam, int linha, int m[linha][tam]){
    int contador = 0;

    for (int col = 0; col < tam; col++)
            if (m[linha][col] == 0) contador++;

    return contador;
}