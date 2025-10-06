/*
    CSES 3311 - Grid Coloring I
    https://cses.fi/problemset/task/3311
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char grid[501][501], ans[501][501];
int n, m; 

bool isValid(int i, int j, char c) {
    vector <pair<int,int>> pos = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

    for (auto &[x, y] : pos) {
        int lin = x + i,
            col = y + j;
        
        if (lin >= 0 && lin < n && col >= 0 && col < m) {
            if (ans[lin][col] == c) 
                return false;
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            ans[i][j] = '-';
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (char c = 'A'; c <= 'D'; ++c) {
                if (c == grid[i][j]) continue;
                if (isValid(i, j, c)) {
                    ans[i][j] = c;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}