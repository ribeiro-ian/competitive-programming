#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll dp[n][3];

    cin >> dp[0][0] >> dp[0][1] >> dp[0][2] ;
    for (int i = 1; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
    }

    ll ans = dp[n-1][0];
    for (int i = 0; i < 3; ++i) 
        ans = max(ans, dp[n-1][i]);

    cout << ans << '\n';

    return 0;
}