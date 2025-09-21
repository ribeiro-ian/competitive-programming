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

    ll n, W, total = 1; cin >> n >> W;
    vector <ll> w(n), v(n);

    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i], total += v[i];

    vector <ll> dp(total, INT_MAX);
    dp[0] = 0; // valor 0 não custa peso algum
    for (int i = 0; i < n; ++i) {
        for (int j = total; j >= v[i]; --j) {
            // para cada valor j, guarda o menor peso para esse valor
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // pegar o maior valor para um peso <= W
    ll ans = 0;
    for (ll i = 0; i < total; ++i)
        if (dp[i] <= W) ans = i;

    cout << ans << '\n';

    return 0;
}