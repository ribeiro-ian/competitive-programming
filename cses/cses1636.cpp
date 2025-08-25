/*
    CSES 1636 - Coin Combinations II
    https://cses.fi/problemset/task/1636
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;   
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, n;
    const ll MOD = 1e9+7;
    cin >> n >> x;
    
    vector <ll> coins(n);
    for (auto &i : coins) cin >> i;

    sort(coins.begin(), coins.end());
    vector <ll> dp(x + 1, 0);

    dp[0] = 1;
    for (ll val = 1; val <= x; ++val) {
        for (auto &coin : coins) {

        }
    }
    
    cout << dp[x] << '\n';
    
    return 0;
}