/*
    AtCoder DP Contest - Frog 1
    https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int vec[n];
    for (auto &i : vec) cin >> i;

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(vec[1] - vec[0]);

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(vec[i] - vec[i-1]),
                    dp[i-2] + abs(vec[i] - vec[i-2])); 
    }

    cout << dp[n-1] << "\n";

    return 0;
}