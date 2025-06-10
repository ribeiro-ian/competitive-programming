/*
    CSES 1193 - Labyrinth
    https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MAX = 1123;
int grid[MAX][MAX];
int vertical[] = {1, -1, 0, 0},
    horizontal[] = {0, 0, 1, -1};
int n, m;

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
    
    bfs(start.first, start.second);        

    int ans = grid[end.first][end.second];
    if (ans <= 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    printf("%i\n", ans-1);

    stack <char> path;
    int lin, col;
    tie(lin,col) = end;

    while (ans > 1) {
        for (int i = 0; i < 4; i++) {
            int v = vertical[i],
                h = horizontal[i];
            int x = lin + v,
                y = col + h;

            if (grid[x][y] == ans-1 && x >= 0 && x < n && y >= 0 && y < m) {
                if (v) {
                    path.push( v == 1 ? 'U' : 'D' );
                }
                if (h) {
                    path.push( h == 1 ? 'L' : 'R' );
                }

                lin = x;
                col = y;
                break;
            }
        }
        ans--;
    }

    while (!path.empty()) {
        printf("%c", path.top());
        path.pop();
    }
    printf("\n");

    return 0;
}
