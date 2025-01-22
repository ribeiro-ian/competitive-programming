#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int COLS, ROWS, hole_cnt, grid[MAX][MAX];
char c;

void bfs(int lin, int col){
    if (lin < 1 || col < 1 || lin > ROWS || col > COLS)
        return;

    if (grid[lin][col] != -1)
        return;

    grid[lin][col] = hole_cnt;

    bfs(lin+1, col);
    bfs(lin-1, col);
    bfs(lin, col+1);
    bfs(lin, col-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> ROWS >> COLS;

        if (ROWS == 0) break;

        for (int i = 1; i <= ROWS; i++){
            for (int j = 1; j <= COLS; j++){
                cin >> c;

                if (c == '*')
                    grid[i][j] = 0;
                else
                    grid[i][j] = -1;
            }
        }

        hole_cnt = 1;
        for (int i = 1; i <= ROWS; i++){
            for (int j = 1; j <= COLS; j++){
                if (grid[i][j] == -1){
                    bfs(i, j);
                    hole_cnt++;
                }
            }
        }

        // for (int i = 1; i <= ROWS; i++){
        //     for (int j = 1; j <= COLS; j++){
        //         if (grid[i][j] == 0)
        //             printf(" - ");
        //         else
        //             printf("%2d ", grid[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");


        cout << hole_cnt-1 << endl;
    }

    return 0;
}
