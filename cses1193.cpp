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
int vertical[] = {1, -1, 0, 0};
int horizontal[] = {0, 0, 1, -1};

void bfs(int i, int j) {
    queue <pii> q;

    grid[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        int lin, col;
        tie(lin,col) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = vertical[i] + lin,
                y = horizontal[i] + col;

            if (grid[x][y] == 0 && x >= 0 && x < n && y >= 0 && y < m) {
                q.push({x,y});
                grid[x][y] = grid[lin][col]+1;
            }
        }
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

    int ans = grid[end.first][end.second];
    if (ans <= 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    printf("%i\n", ans-1);

    
    
    stack <char> path;
    int v = ans, lin, col;
    tie(lin,col) = end;

    while (v > 1) {
        printf("<%i,%i>\n", lin+1, col+1);
        for (int i = 0; i < 4; i++) {
            int x = vertical[i] + lin,
                y = horizontal[i] + col;

            if (grid[x][y] == v-1 && x >= 0 && x < n && y >= 0 && y < m) {
                if (x) {
                    path.push( x == 1 ? 'U' : 'D');
                }
                if (y) {
                    path.push( y == 1 ? 'R' : 'L' );
                }

                lin = x;
                col = y;
                break;
            }
        }
        v--;
    }

    while (!path.empty()) {
        printf("%c", path.top());
        path.pop();
    }
    printf("\n");
    
        

    return 0;
}
