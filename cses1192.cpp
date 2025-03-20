/*
    CSES 1192 - Counting Rooms
    https://cses.fi/problemset/task/1192
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int n, m;
const int MAX = 11234;
char matriz[MAX][MAX];

void bfs(int i, int j) {
    queue <pii> fila;

    matriz[i][j] = '1';
    fila.push(make_pair(i,j));

    while (!fila.empty()) {
        int lin = fila.front().first,
            col = fila.front().second;
        fila.pop();

        matriz[lin][col] = '1';

        if (matriz[lin+1][col] == '.' && lin+1 < n)
            fila.push(make_pair(lin+1,col));
        if (matriz[lin-1][col] == '.' && lin-1 >= 0)
            fila.push(make_pair(lin-1,col));
        if (matriz[lin][col+1] == '.' && col+1 < m)
            fila.push(make_pair(lin,col+1));
        if (matriz[lin][col-1] == '.' && col-1 >= 0)
            fila.push(make_pair(lin,col-1));
    }
}


int main() {

    scanf("%i%i", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &matriz[i][j]);
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == '.'){
                bfs(i,j);
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("%i\n", cnt);
    
    return 0;
}
