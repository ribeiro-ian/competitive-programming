/*
    CSES 1690 - Hamiltonian Flights
    https://cses.fi/problemset/task/1690
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 21;
int n, m, dp[1 << MAX][MAX];
bool dist[MAX][MAX];

int solve(ll mask, ll i) {
    if (mask == (1 << n) - 1) return dp[mask][i]++;
    if (!dp[mask][i]) return dp[mask][i];

    int ans = 1e9;
    for (int j = 1; j <= n; ++j) {
        if (mask & (1 << j) || !dist[i][j]) continue;

        ans = min(ans, solve(mask | (1 << j), j) % (int)(1e9+7) + 1);
    }

    return dp[mask][i] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
    }
    memset(dp, 0, sizeof(dp));
    cout << solve(1,1) << '\n';

    return 0;
}