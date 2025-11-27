/*
    CSES 3359 - Minimal Grid Path
    https://cses.fi/problemset/task/3359
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    char grid[n+1][n+1];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
        
    int sz[n+1][n+1];

    string dp[n+1][n+1];
    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j <= n; ++j) {
            dp[i][j].push_back('Z'+1);
            sz[i][j] = 'Z'+1;
        }

    sz[1][1] = grid[1][1];
    dp[1][1] = grid[1][1]; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i==1 && j == 1) continue;

            if (sz[i-1][j] < sz[i][j]) 
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];

            sz[i][j] += min(grid[i-1][j], grid[i][j-1]);
            dp[i][j] += grid[i][j];
        }
    }
    
    cout << dp[n][n] << "\n";

    return 0;
}