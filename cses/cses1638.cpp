/*
    CSES 1638 - Grid Paths I
    https://cses.fi/problemset/task/1638
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const ll INF = INT_MAX,
             MOD = 1e9+7;
    ll n; cin >> n;
    vector <vector<ll>>
        grid(n+1, vector <ll>(n+1,0)), 
        sum(n+1, vector <ll>(n+1,0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '*') grid[i][j] = -INF;
        }
    }

    sum[1][0] = 1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (grid[i][j] == -INF) continue;
            sum[i][j] = (sum[i][j-1] + sum[i-1][j]) % MOD;
        }
    }
    
    cout << sum[n][n] << '\n';

    return 0;
}