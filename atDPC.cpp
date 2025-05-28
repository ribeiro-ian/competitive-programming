/*
    AtCoder DP Contest - Vacation
    https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll v[n][3];

    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    ll dp[3][n];
    for (int k = 0; k < 3; k++) {
        dp[k][0] = v[0][k];

        ll ultimo = k;
        for (int i = 1; i < n; ++i) {
            dp[k][i] = dp[k][i-1];

            ll maior = 0, maiorIdx = -1;
            for (int j = 0; j < 3; ++j) {
                if (j == ultimo) continue;

                if (v[i][j] > maior) {
                    maior = v[i][j];
                    maiorIdx = j;
                }
            }

            dp[k][i] += maior;
            ultimo = maiorIdx;
        }    
    }

    ll ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = max(ans, dp[i][n-1]);
    }

    cout << ans << endl;

    return 0;
}