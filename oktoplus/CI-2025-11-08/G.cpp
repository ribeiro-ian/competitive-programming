#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MAX = 2000+1;
int n, m;
char grid[MAX][MAX];

// D L R U
pii move[] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
char dir[] = {'D', 'L', 'R', 'U'};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    pii st, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') st = {i,j};
            if (grid[i][j] == 'E') end = {i,j};
        }
    }

    
    
    return 0;
}