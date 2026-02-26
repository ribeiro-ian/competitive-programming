/*
    CSES 1717 - Christmas Party
    https://cses.fi/problemset/task/1717
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1e9+7;

ll f(ll x) {
    if (x <= 2) return x - 1;

    return (x-1) * (f(x-1) + f(x-2)) % M;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector<ll> dp(n+1);
    
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) 
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % M;
    
    cout << dp[n] << '\n';

    return 0;
}