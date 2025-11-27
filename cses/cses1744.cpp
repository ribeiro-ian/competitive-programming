/*
    CSES 1744 - Rectangle Cutting
    https://cses.fi/problemset/task/1744
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector <vector<int>> dp(a+1, vector <int>(b+1, 1e9));
    
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << '\n';
    
    return 0;
}