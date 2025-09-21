/*
    AtCoder DP Contest - Matching
    https://atcoder.jp/contests/dp/tasks/dp_o
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, mod = 1e9+7;
    cin >> n;
    bool grid[n][n];
    vector <int> dp(1 << n);

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> grid[i][j];

    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int row = __popcount(mask);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i) || !grid[row][i]) continue;

            dp[mask | (1 << i)] = (dp[mask | (1 << i)] + dp[mask]) % mod;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';

    return 0;
}