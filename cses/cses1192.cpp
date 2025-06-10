/*
    CSES 1192 - Counting Rooms
    https://cses.fi/problemset/task/1192
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e3+5;
int grid[MAX][MAX];
int n, m;

void dfs(int lin, int col){
    grid[lin][col] = 1;

    int vertical[] = {lin+1, lin-1};
    int horizontal[] = {col+1, col-1};

    for (auto d : vertical) {
        if (grid[d][col] == 0 && d >= 0 && d < n) {
            dfs(d,col);
        }
    }
    for (auto d : horizontal) {
        if (grid[lin][d] == 0 && d >= 0 && d < m) {
            dfs(lin,d);
        }
    }
}

int main() {
    string line;
    scanf("%i%i", &n, &m);

    for (int i = 0, j = 0; i < n; i++) {
        cin >> line;
        for (auto &c : line) {
            if (c == '.') grid[i][j] = 0;
            else grid[i][j] = -1;
            j++;
        }
        j = 0;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0){
                dfs(i,j);
                cnt++;
            }
        }
    }

    printf("%i\n", cnt);

    return 0;
}
