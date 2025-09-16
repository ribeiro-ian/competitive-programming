/*
    AtCoder DP Contest - Knapsack 2
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
    ll n = (ll) s.size(),
       m = (ll) t.size();
    
    vector <vector <ll>> dp (n+1, vector <ll> (m+1, 0));

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

    cout << dp[n][m] << '\n';

    return 0;
}