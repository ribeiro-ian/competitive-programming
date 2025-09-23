/*
    Codeforces 1316E - Team Building
    https://codeforces.com/contest/1316/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, p, k;
    cin >> n >> p >> k;
    
    vector <ll> v(n+1);
    ll grid[n+1][p];
    for (int i = 1; i <= n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());

    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < p; ++j) 
            cin >> grid[i][j];

    vector <ll> dp[n][1<<p]
    for (int mask = 1; mask < (1 << p); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int aux = mask ^ (i << i);

                dp[i][mask] = dp[i][aux] + grid[i][j]
            }
        }
    }
    cout << dp[n][(1 << p)] << '\n';
    

    return 0;
