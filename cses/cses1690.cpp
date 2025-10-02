/*
    CSES 1690 - Hamiltonian Flights
    https://cses.fi/problemset/task/1690
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool adj[n+1][n+1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
    }

    int dp[1 << n][n+1];
    memset(dp, 0, sizeof(dp));

    for (int mask = 1; mask < (1 << n); ++mask) {
        
    }

    return 0;
}