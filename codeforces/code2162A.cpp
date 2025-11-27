/*
    Codeforces 2162A - Beautiful Average
    https://codeforces.com/contest/2162/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n; cin >> n;
    vector <int> pref(n+1);
    
    int ans = 0;
    for (int i = 0, x; i < n;++i) {
        cin >> x;
        ans = max(ans, x);
        pref[i+1] = pref[i] + x;
    }
    
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = max(ans, (pref[j]-pref[j-i])/i);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}