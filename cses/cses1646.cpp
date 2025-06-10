/*
    CSES 1646 - Static Range Sum Queries
    https://cses.fi/problemset/task/1646
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, q, l, r;
    cin >> n >> q;

    vector <ll> v (n), pref(n+1); 
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];
    
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    
    return 0;
}

