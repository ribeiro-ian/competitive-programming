/*
    CSES 1644 - Maximum Subarray Sum II
    https://cses.fi/problemset/task/1644
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n, a, b;
    cin >> n >> a >> b;
 
    vector <ll> pref(n+1);
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        pref[i] = pref[i-1] + x;
    }

    ll ans = -1e18;
    multiset<ll> freq;

    for (ll i = a; i <= n; ++i) {
        if (i > b) freq.erase(freq.find(pref[i - b - 1]));

		freq.insert(pref[i - a]);
		ans = max(ans, pref[i] - *freq.begin());
    }
        
    cout << ans << '\n';
 
    return 0;
}