/*
    CSES 1753 - String Matching
    https://cses.fi/problemset/task/1753
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6+1, M = 1e9+7, P = 31;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, t;
    cin >> s >> t;
    
    ll n = s.size(), m = t.size();
    if (m > n || (m == n && s != t)) {
        cout << 0 << '\n';
        return 0;
    }
    
    vector<ll> h(n+1, 0);
    vector<ll> p(n+1, 1);

    for (int i = 1; i <= n; ++i) 
        p[i] = (p[i-1] * P) % M;    
    
    for (int i = 1; i <= n; ++i)
        h[i] = (h[i-1] * P + (s[i-1]-'a'+1)) % M;
    
    ll ht = 0, ans = 0;
    for (int i = 0; i < m; ++i) 
        ht = (ht * P + (t[i]-'a'+1)) % M;

    for (int i = 0; i <= n-m; ++i) {
        ll hs = (h[i+m] - (h[i] * p[m]) % M + M) % M;
        
        ans += (hs == ht);
    }

    cout << ans << '\n';

    return 0;
}