/*
    CSES 1653 - Elevator Rides
    https://cses.fi/problemset/task/1653/
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, x;
    cin >> n >> x;
    ll w[n];
    for (auto &i : w) cin >> i;

    vector <pair <ll,ll>> dp(1<<n);
    dp[0] = {1,0}; // caso base
    for (int mask = 1; mask < (1<<n); ++mask) {
        dp[mask] = {n+1, 0};

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                auto aux = dp[mask ^ (1 << i)]; // mask ^ (1 << i) - remove i do subset
                
                if (aux.second + w[i] <= x) {
                    aux.second += w[i];
                }
                else {
                    aux.first++;
                    aux.second = w[i];
                }
                dp[mask] = min(dp[mask], aux);
            }
        }
    }
    cout << dp[(1<<n)-1].first << '\n';
 
    return 0;
}