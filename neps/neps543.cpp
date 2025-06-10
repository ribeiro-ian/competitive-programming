/*
    Neps 543 - Batalha Naval
    https://neps.academy/br/exercise/543
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, k, l, c;
string line;
vector <vector<int>> grid;
vector <int> ships;

int vertical[] = {0,0,1,-1};
int horizontal[] = {1,-1,0,0};


void dfs(int lin, int col, int id) {
    grid[lin][col] = id;
    ships[id]++;

    for (int i = 0; i < 4; i++) {
        int x = lin + vertical[i],
            y = col + horizontal[i];

        if (x >= 1 && x <= n && y >= 1 && y <= m && grid[x][y] == 0) {
            dfs(x, y, id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    grid.assign(n+1, vector<int> (m+1, 0));

    for (int i = 1, j = 1; i <= n; i++) {
        cin >> line;
        for (auto &ch : line) {
            grid[i][j] = (ch == '.' ? -1 : 0);
            j++;
        }
        j = 1;
    }
    
    ships.push_back(0);
    for (int i = 1, id = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 0) {
                ships.push_back(0);
                dfs(i, j, id);
                id++;
            }
        }
    }

    int cnt = 0;
    cin >> k;
    while (k--) {
        cin >> l >> c;

        if (grid[l][c] >= 1) {
            ships[grid[l][c]]--;
               
            if (ships[grid[l][c]] <= 0) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}