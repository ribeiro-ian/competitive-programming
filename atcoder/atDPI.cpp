/*
    AtCoder DP Contest - Coins
    https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <double> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    vector <double> dp(n+1); // prob de i heads
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j >= 0; --j) {
            dp[j] = dp[j] * (1-p[i]);
            if (j)
                dp[j] += dp[j-1] * p[i];
        }
    }
    double ans = 0;
    for (int heads = 0; heads <= n; ++heads) {
        int tails = n-heads;
        if (heads > tails) ans += dp[heads];
    }
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}