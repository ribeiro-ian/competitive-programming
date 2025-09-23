/*
    OBI 2015 Segunda Fase - Mina
    https://neps.academy/br/exercise/65
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int INF = 1e9;
int grid[101][101], dist[101][101], n;
pii pos[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void bfs(int i, int j) {
    queue <pii> q;
    q.push({i,j});
    dist[i][j] = 0;
    
    while (!q.empty()) {
        int lin, col;
        tie(lin, col) = q.front();
        q.pop();

        for (auto [v, h] : pos) {
            int x = lin+v,
                y = col+h;
            
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (dist[lin][col] + grid[x][y] < dist[x][y]) {
                    q.push({x,y});
                    dist[x][y] = dist[lin][col] + grid[x][y];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            dist[i][j] = INF;
        }
    }
        
    bfs(0,0);
    cout << dist[n-1][n-1] << '\n';

    return 0;
}