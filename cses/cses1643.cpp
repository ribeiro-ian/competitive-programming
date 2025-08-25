/*
    CSES 1643 - Maximum Subarray Sum
    https://cses.fi/problemset/task/1643
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
 
    vector <ll> v(n), dp(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
 
    ll ans; ans = dp[0] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i-1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }
        
    cout << ans << '\n';
 
    return 0;
}