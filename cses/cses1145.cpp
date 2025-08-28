/*
    CSES 1145 - Increasing Subsequence
    https://cses.fi/problemset/task/1145
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) cin >> i;

    vector<int> dp;
    dp.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] > dp.back()) {
            dp.push_back(v[i]);
        }
        else {
            int aux = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[aux] = v[i];
        }
    }
    cout << dp.size() << '\n';

    return 0;
}