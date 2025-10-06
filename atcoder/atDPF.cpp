/*
    AtCoder DP Contest - LCS
    https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, t;
    cin >> s >> t;
    ll n = (int) s.size(),
       m = (int) t.size();
    
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans = s[i-1] + ans;
            i--, j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }   

    cout << ans << '\n';

    return 0;
}