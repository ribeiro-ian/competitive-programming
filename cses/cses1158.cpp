/*
    CSES 1158 - Book Shop
    https://cses.fi/problemset/task/1158
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector <ll> prices(n), pages(n);

    for (auto &i : prices) cin >> i;
    for (auto &i : pages) cin >> i;
    
    vector <ll> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int c = x; c > 0; c--) {
            if (prices[i] > c) continue;
            dp[c] = max(dp[c], pages[i] + dp[c - prices[i]]);
        }
    }

    cout << dp[x] << '\n';

    return 0;
}