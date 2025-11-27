/*
    Codeforces 189A - Cut Ribbon
    https://codeforces.com/problemset/problem/189/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    set<ll> len;
    
    cin >> n;
    vector<ll> dp(n+1);

    for (int i = 0; i < 3; ++i) {
        ll x; cin >> x;
        len.insert(x);
    }
    
    for (int x = 0; x <= n; ++x) {
        if (!dp[x] && x != 0) continue;
        for (auto &v : len) {
            if (x+v <= n) 
                dp[x+v] = max(dp[x+v], dp[x]+1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}