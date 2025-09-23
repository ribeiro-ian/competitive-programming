/*
    CSES 1193 - Labyrinth
    https://cses.fi/problemset/task/1193
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MAX = 1000+1;
int grid[MAX][MAX], n, m;
pii pos[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void bfs(int i, int j) {
    queue <pii> q;

    grid[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        int lin, col;
        tie(lin,col) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = lin + pos[i].first,
                y = col + pos[i].second;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                q.push({x,y});
                grid[x][y] = grid[lin][col]+1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    pii st, end;

    for (int i = 0, j = 0; i < n; i++, j=0) {
        string line; cin >> line;
        for (auto &c : line) {
            grid[i][j] = 0;

            if (c == '#')
                grid[i][j] = -1;

            if (c == 'A')
                st = {i,j};
            else if (c == 'B')
                end = {i,j};
            j++;
        }
    }
    
    bfs(st.first, st.second);        

    int ans = grid[end.first][end.second];
    if (ans <= 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << ans - 1 << '\n';

    stack <char> path;
    int lin, col;
    tie(lin,col) = end;

    while (ans > 1) {
        for (int i = 0; i < 4; i++) {
            int v, h;
            tie(v,h) = pos[i];

            int x = lin + v,
                y = col + h;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == ans-1) {
                if (v) 
                    path.push( v == 1 ? 'U' : 'D' );
                if (h) 
                    path.push( h == 1 ? 'L' : 'R' );

                lin = x;
                col = y;
                break;
            }
        }
        ans--;
    }

    while (!path.empty()) {
        cout << path.top();
        path.pop();
    }
    cout << '\n';

    return 0;
}
