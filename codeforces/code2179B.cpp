/*
    Codeforces 2179B - Blackslex and Showering
    https://codeforces.com/contest/2179/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, sum = 0;
    cin >> n;
    
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        
        if (i > 0) 
            sum += abs(v[i]-v[i-1]);        
    }
    
    ll ans = min(sum - abs(v[1]-v[0]), sum - abs(v[n-1] - v[n-2]));
    for (int i = 1; i < n-1; ++i) {        
        ll calc = sum - abs(v[i]-v[i-1]) - abs(v[i+1]-v[i]) + abs(v[i+1]-v[i-1]);

        ans = min(ans, calc);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}