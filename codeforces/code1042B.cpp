/*
    Codeforces 1042B - Vitamins
    https://codeforces.com/contest/1042/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, sz = 3; cin >> n;
    vector <int> dp(1 << sz, 1e9);

    for (int i = 0; i < n; ++i) {
        int c; string str;
        cin >> c >> str;

        int mask = 0;
        for (auto &i : str) mask += (1 << (int)(i-'A'));
        dp[mask] = min(dp[mask], c);
    }
    
    dp[0] = 0;
    for (int mask = 1; mask < (1 << sz); ++mask) {
        for (int submask = 1; submask < (1 << sz); ++submask) {
            if (mask | submask == (1<<sz)-1) {
                dp[mask | submask] = min(dp[mask | submask], dp[mask] + dp[submask]);
            }

        }
    }
    cout << (dp[(1<<sz)-1] != 1e9 ? dp[(1<<sz)-1] : -1) << endl;

    return 0;
}