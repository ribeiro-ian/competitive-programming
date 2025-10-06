/*
    CSES 3217 - Knight Moves Grid
    https://cses.fi/problemset/task/3217
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector <int> pos1 = {-1,1};
vector <int> pos2 = {-2,2}; 

int n, grid[1001][1001];
void bfs(int i = 0, int j = 0) {
    int v = 0;
    grid[i][j] = 0;

    queue <pii> q;
    q.push({i,j});

    while (!q.empty()) {
        tie(i,j) = q.front();
        q.pop();

        v = grid[i][j];
        for (auto &x : pos1) {
            for (auto &y : pos2) {
                int lin1 = i + x,
                    col1 = j + y;

                if (lin1 >= 0 && lin1 < n && col1 >= 0 && col1 < n && grid[lin1][col1] == -1) {
                    grid[lin1][col1] = v + 1;
                    q.push({lin1,col1});
                }

                int lin2 = i + y,
                    col2 = j + x;

                if (lin2 >= 0 && lin2 < n && col2 >= 0 && col2 < n && grid[lin2][col2] == -1) {
                    grid[lin2][col2] = v + 1;
                    q.push({lin2,col2});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(grid, -1, sizeof(grid));
    cin >> n;

    bfs();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}