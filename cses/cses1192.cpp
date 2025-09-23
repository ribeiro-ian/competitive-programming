/*
    CSES 1192 - Counting Rooms
    https://cses.fi/problemset/task/1192
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
pair <int,int> pos[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
char grid[1001][1001];

void dfs(int i, int j) {
    if (grid[i][j] != '.') return;
    grid[i][j] = '#';

    for (auto &[x, y] : pos) {
        int lin = i + x, col = j + y;
        if (lin >= 0 && lin < n && col >= 0 && col < m)
            dfs(lin, col);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> grid[i][j];

    int cnt = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (grid[i][j] == '.')
                dfs(i,j), cnt++;
    
    cout << cnt << '\n';
    
    return 0;
}