/*
    CSES 2216 - Collecting Numbers
    https://cses.fi/problemset/task/2216
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n; cin >> n;
    vector <ll> v(n);
    map <ll,ll> freq;
    for (int i = 1; i <= n; ++i) freq[i] = 0;
 
    ll cnt = 1;
    for (auto &i : v) {
        cin >> i;
        
        if (freq[i-1] == 0) {
            freq[i] = cnt;
            cnt++;
        }
        else {
            freq[i] = freq[i-1];
        }
    }       
    for (auto &i : v) {
        cerr << freq[i] << ' ';
    }
    cerr << '\n';
 
    cout << cnt-1 << '\n';
 
    return 0;
}