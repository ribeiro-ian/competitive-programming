/*
    CSES 1643 - Maximum Subarray Sum
    https://cses.fi/problemset/task/1643
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;

    vector <ll> pref(n+1);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        pref[i+1] = pref[i] + x;
    }
    
    

    cout << ans << '\n';

    return 0;
}