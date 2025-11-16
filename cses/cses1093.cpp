/*
    CSES 1093 - Two Sets II
    https://cses.fi/problemset/task/1093
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int MOD = 1e9+7;
    int n; cin >> n;
    int sum = n*(n+1)/2;

    if (sum%2) {
        cout << "0\n";
        return 0;
    }
    int target = sum/2;
    int dp[target+1] = {0};

    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= i; --j) {
            dp[j] = (dp[j] + dp[j-i]) % MOD;
        }
    }

    cout << dp[target] << '\n';

    return 0;
}