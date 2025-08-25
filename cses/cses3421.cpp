/*
    CSES 3421 - Distinct Values Subsequences
    https://cses.fi/problemset/task/3421
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const ll MOD =  1e9+7;
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) cin >> i;

    multiset <ll> freq;
    vector <ll> dp(n, 0);
    freq.insert(v[0]); dp[0] = 1;

    for (ll i = 1; i < n; ++i) {
        dp[i] = (2 * dp[i-1]) % MOD;

        if (freq.count(v[i])) dp[i] = (dp[i] - freq.count(v[i])) % MOD;
        else dp[i]++;
        if (freq.count(v[i]) > 1) dp[i]--;

        freq.insert(v[i]);
    }

    cout << dp[n-1] << '\n';

    return 0;
}