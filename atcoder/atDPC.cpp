/*
    AtCoder DP Contest - Vacation
    https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll v[n][3];

    for (int i = 0; i < n; ++i) 
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    ll dp[n][3];
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = v[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    ll ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans << "\n";

    return 0;
}