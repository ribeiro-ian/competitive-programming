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

    const int M = 1e9+7;
    int n; cin >> n;
    int total = n*(n+1)/2;

    if (total % 2) {
        cout << "0\n";
        return 0;
    }
    int half = total / 2;

    // dp[n][half+1] pois iremos considerar que N estará no outro subset
    // Dessa forma, teremos a quantidade de pares que somam half
    vector <vector <int>> dp (n, vector <int> (half+1, 0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int s = 1; s <= half; ++s) {
            if (s < i)
                dp[i][s] = dp[i-1][s];
            else
                dp[i][s] = (dp[i - 1][s] + dp[i - 1][s - i]) % M;
        }
    }

    cout << dp[n-1][half] << '\n';

    return 0;
}