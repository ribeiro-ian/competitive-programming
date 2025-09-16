/*
    AtCoder DP Contest - Knapsack 2
    https://atcoder.jp/contests/dp/tasks/dp_e
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, W; cin >> n >> W;
    vector <ll> w(n), v(n);

    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

    vector <ll> dp(W+1);

    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << '\n';

    return 0;
}