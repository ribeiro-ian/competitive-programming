/*
    CSES 1158 - Book Shop
    https://cses.fi/problemset/task/1158
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector <ll> prices(n), pages(n);

    for (auto &i : prices) cin >> i;
    for (auto &i : pages) cin >> i;

    vector <pll> dp(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = {0, 0};
        
        for (int j = 0; j < i; j++) {
            if (dp[j].first + prices[i] <= x && dp[j].second + pages[i] > dp[i].second) {
                dp[i] = { dp[j].first + prices[i], dp[j].second + pages[i]};
            }
            if (prices[j] + prices[i] <= x && pages[j] + pages[i] > dp[i].second) {
                dp[i] = { prices[j] + prices[i], pages[j] + pages[i]};
            }
        }
        
        ans = max(ans, dp[i].second);
    }

    cout << ans << '\n';
    
    
    return 0;
}