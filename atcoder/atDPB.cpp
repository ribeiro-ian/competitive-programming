/*
    AtCoder DP Contest - Frog 2
    https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector <int> vec(n);
    for (auto &i : vec) cin >> i;

    vector <int> dp(n,INT_MAX);
    dp[0] = 0;

    for (int i = 1, j; i < n; i++) {
        j = i - 1;

        while (j >= 0 && i-j <= k) {
            dp[i] = min(dp[i], dp[j] + abs(vec[i] - vec[j]));
            j--;
        }
    }

    cout << dp[n-1] << "\n";

    return 0;
}