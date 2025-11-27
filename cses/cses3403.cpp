/*
    CSES 3403 - Longest Common Subsequence
    https://cses.fi/problemset/task/3403
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
 
    vector<int> a(n), b(m);
    for(auto &i : a) cin>>i;
    for(auto &i : b) cin>>i;
 
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector <int> ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i-1]);
            i--, j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    cout << dp[n][m] << '\n';
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << '\n';
 
    return 0;
}