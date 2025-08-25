/*
    CSES 1634 - Minimizing Coins
    https://cses.fi/problemset/task/1634
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, n;
    cin >> n >> x;
    
    vector <ll> coins(n);
    for (auto &i : coins) cin >> i;

    sort(coins.begin(), coins.end());
    vector <ll> dp(x + 1, INT_MAX);

    dp[0] = 0;
    for (auto &coin : coins) {
        for (ll val = coin; val <= x; ++val) {
            dp[val] = min(dp[val], dp[val - coin] + 1);
        }
    }
    
    cout << (dp[x] != INT_MAX ? dp[x] : -1) << "\n";

    return 0;
}