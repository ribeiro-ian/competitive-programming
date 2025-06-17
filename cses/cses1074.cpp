/*
    CSES 1074 - Stick Lengths
    https://cses.fi/problemset/task/1074
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n; cin >> n;
    vector <ll> v(n);
 
    for (auto &i : v)  cin >> i;
    
    sort(v.begin(), v.end());
    for (auto &i : v)  cerr << i << ' '; cerr << '\n';
    ll ans = 0, m = v[n/2];
    for (auto &i : v) {
        ans += abs(i-m);
    }
 
    cout << ans << '\n';
 
    return 0;
}