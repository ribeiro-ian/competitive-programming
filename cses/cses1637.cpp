/*
    CSES 1637 - Removing Digits
    https://cses.fi/problemset/task/1637
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void bestDigit(ll num, vector <ll> &dp) {
    string digits = to_string(num);

    for (auto &c : digits) {
        ll digit = (ll) c - '0';
        dp[num] = min(dp[num], dp[num - digit]);
    }

    dp[num]++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> dp(n+1, INT_MAX);
    dp[0] = 0;

    for (ll i = 1; i <= n; ++i) 
        bestDigit(i, dp);

    cout << dp[n] << '\n';

    return 0;
}