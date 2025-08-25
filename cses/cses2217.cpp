/*
    CSES 2217 - Collecting Numbers II
    https://cses.fi/problemset/task/2217
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n, m; cin >> n >> m;
    vector <ll> v(n);
    map <ll,ll> freq;
    for (int i = 1; i <= n; ++i) freq[i] = 0;
 
    ll cnt = 0;
    for (auto &i : v) {
        cin >> i;
        
        if (freq[i-1] == 0) {
            cnt++;
            freq[i] = cnt;
        }
        else {
            freq[i] = freq[i-1];
        }
    }
    while (m--) {
        ll x, y, a, b;
        cin >> x >> y;
        a = min(x,y);
        b = max(x,y);
        
    }
    for (auto &i : v) {
        cerr << freq[i] << ' ';
    }
    cerr << '\n';
 
    cout << cnt << '\n';
 
    return 0;
}