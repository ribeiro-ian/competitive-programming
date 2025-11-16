/*
    CSES 3359 - Minimal Grid Path
    https://cses.fi/problemset/task/3359
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> grid[i][j];
    
    vector <vector <pii>> dp (n, vector <pii> (n, {0,0}));
    
    dp[0][0] = {0,0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c = 'Z';
            pii prev = {n,n};

            if (i-1 >= 0 && grid[i-1][j] <= c) {
                c = grid[i-1][j];
                prev = {i-1, j};
            }
            if (j-1 >= 0 && grid[i][j-1] <= c) {
                c = grid[i][j-1];
                prev = {i, j-1};
            }

            dp[i][j] = prev;
        }
    }
    string ans = 0;
    cout << ans << '\n';

    return 0;
}