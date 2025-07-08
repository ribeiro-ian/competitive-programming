/*
    CSES 3311 - Grid Coloring I
    https://cses.fi/problemset/task/3311
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<vector<char>> grid;
vector<vector<char>> ans;
ll n, m;

bool valid(int i, int j, char ch) {
    vector <pair <int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    for (auto [x,y] : dir) {
        int lin = i + x,
            col = j + y;
        
        if (lin >= 0 && lin < n && col >=0 && col < m) {
            if (ans[lin][col] == ch) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    grid.assign(n, vector<char> (m, '-'));
    ans.assign(n, vector<char> (m, '-'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
            
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            for (char c = 'A'; c <= 'D'; ++c) {
                if (grid[i][j] == c) continue;
                
                if (valid(i,j,c)) {
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