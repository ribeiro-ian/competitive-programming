/*
    CSES 1645 - Nearest Smaller Values
    https://cses.fi/problemset/task/1645
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> v(n+1), dp(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    dp[1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (v[i-1] < v[i]) {
            dp[i] = i-1;
        }
        else {
            ll idx = i-1;
            while (v[i] <= v[idx]) {
                idx = dp[idx];
            }
            dp[i] = idx;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}