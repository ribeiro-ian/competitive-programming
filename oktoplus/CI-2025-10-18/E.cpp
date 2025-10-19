#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
bool validPos(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    char grid[n][m];
    int path[n][m];
    vector <int> row(n+1,0), col(m+1,0);
    pii s, e;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            grid[i][j] = c;
            
            if (c=='S') s = {i,j};
            else if (c=='E') e = {i,j};

            row[i+1] = row[i] + (c=='X');
            col[j+1] = col[j] + (c=='X');
        }
    }

    for (auto &i : row) 
        cerr << i << ' '; cerr << '\n';
    
    
    unordered_map <char, pii> dir = {
        {'D', {1,0}},
        {'U', {-1,0}},
        {'L', {0,1}},
        {'D', {0,-1}},
    };
    path[s.first][s.second] = 0;
    queue<pii> q;
    q.push(s);

    while (!q.empty()) {
        int i, j;
        tie(i,j) = q.front();
        q.pop();
        
        int v = path[i][j];
        for (auto &m : dir) {
            int x,y; tie(x,y) = m.second;

            i += x, j += y;

            if (validPos(i, j)) {
                if (grid[i][j] != 'X') {
                    path[i][j] = v+1;
                    q.push({i,j});
                }
                else {
                    // y1 = y2, mesma coluna
                    // if (y == 0 && ) {

                    // }
                }
            }
        }
    }

    return 0;
}