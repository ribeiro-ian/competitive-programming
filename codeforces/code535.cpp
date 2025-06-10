/*
    Neps 535 - Colorindo
    https://neps.academy/br/exercise/535
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, m, x, y, k, a, b, cnt;
vector <vector <int>> grid;
int pos[] = {0, 1, -1};

void dfs(int i, int j) {
    grid[i][j] = 1;
    cnt++;

    for (auto &lin : pos) {
        int x = lin + i;
        for (auto &col: pos) {
            y = col + j;
            if (x >= 1 && x <= n && y >= 1 && y <= m && !grid[x][y]) {
                dfs(x, y);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> k;

    grid.assign(n+1, vector <int> (m+1, 0));
    cnt = 0;

    while (k--) {
        cin >> a >> b;
        
        grid[n-a+1][b] = -1;
    }

    dfs(n-x+1, y);
    cout << cnt << '\n';

    return 0;
}