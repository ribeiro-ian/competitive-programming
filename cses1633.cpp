/*
    CSES 1633 - Dice Combinations
    https://cses.fi/problemset/task/1633
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll const MAXN = 1e6+1, MOD = 1e9+7;

ll dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + (dp[i - j])) % MOD;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}