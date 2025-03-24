/*
    CSES 1193 - Labyrinth
    https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n, m;
const int MAX = 1123;
int grid[MAX][MAX];

int bfs(int i, int j) {
    queue <pii> q;

    int cnt = 1;
    grid[i][j] = cnt;
    q.push({i, j});

    while (!q.empty()) {
        int lin, col;
        tie(lin,col) = q.front();
        q.pop();
        
        
        int vertical[] = {lin-1,lin+1};
        int horizontal[] = {col-1,col+1};
        
        for (auto &d : vertical) {
            if (grid[d][col] == 0 && d >= 0 && d <= n) {
                q.push({d, col});
                grid[d][col] = cnt;
            }
        }
        
        for (auto &d : horizontal) {
            if (grid[lin][d] == 0 && d >=0 && d <= m) {
                q.push({lin, d});
                grid[lin][d] = cnt;
            }
        }
        
        cnt++;
    }

}

void gridPrint() {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2i ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string line;
    scanf("%i%i", &n, &m);

    pii start, end;
    for (int i = 0, j = 0; i < n; i++) {
        cin >> line;
        
        for (auto &c : line) {
            if (c == '#')
                grid[i][j] = -1;
            else
                grid[i][j] = 0;

            if (c=='A')
                start = {i,j};
            else if (c=='B')
                end = {i,j};
            j++;
        }
        j = 0;
    }
    
    gridPrint();
    bfs(start.first, start.second);        
    gridPrint();        

    return 0;
}
