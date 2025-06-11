/*
    CSES 1083 - Missing Number
    https://cses.fi/problemset/task/1083/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll v[n];
    for (int i = 0; i < n-1; i++) cin >> v[i];
    
    sort(v, v+n);
    for (ll i = 0; i < n; i++) {
        if (i+1 != v[i]) {
            cout << i+1 << '\n';
            break;
        }
    }
 
    return 0;
}