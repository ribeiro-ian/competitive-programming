#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
int h, w, dice_cnt, pic[MAX][MAX];
vector <int> dice_value;
char c;

void printPic(){
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (pic[i][j] == 0)
                printf(" - ");
            else if (pic[i][j] == -2)
                printf(" X ");
            else
                printf("%2d ", pic[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void find_dot(int lin, int col){
    if (lin < 1 || col < 1 || lin > h || col > w || pic[lin][col] != -2)
        return; // se a pos não é -2/'X', logo n é ponto

    pic[lin][col] = -1; // marca como -1/'*' para o programa a bfs  poder prosseguir
    // printPic();
    find_dot(lin+1, col);
    find_dot(lin-1, col);
    find_dot(lin, col+1);
    find_dot(lin, col-1);
}

void bfs(int lin, int col){
    if (lin < 1 || col < 1 || lin > h || col > w || pic[lin][col] >= 0)
        return; // se a pos assume valor positivo significa q ja foi visitada.

    if (pic[lin][col] == -2){
        dice_value[dice_cnt]++;
        find_dot(lin, col);
    }

    pic[lin][col] = dice_cnt;
    // printPic();
    bfs(lin+1, col);
    bfs(lin-1, col);
    bfs(lin, col+1);
    bfs(lin, col-1);
}

int main(){
    int throw_cnt = 1;

    while(1){
        cin >> w >> h;

        if (h == 0 && w == 0) break;

        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                cin >> c;

                if (c == 'X')
                    pic[i][j] = -2;
                else if (c == '*')
                    pic[i][j] = -1;
                else
                    pic[i][j] = 0;
            }
        }

        dice_cnt = 1;
        dice_value.resize(1);
        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                if (pic[i][j] < 0){
                    dice_value.push_back(0);
                    bfs(i, j);
                    dice_cnt++;
                }
            }
        }

        sort(dice_value.begin(), dice_value.end());

        cout << "Throw " << throw_cnt++ << endl;
        for (int i = 1; i < dice_value.size()-1; i++)
            cout << dice_value[i] << " ";
        cout << dice_value[dice_value.size()-1] << "\n";   

        printf("\n");     
    }

    return 0;
}
