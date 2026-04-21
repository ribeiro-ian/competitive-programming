/*
    Codeforces 1968C - Assembly via Remainders
    https://codeforces.com/problemset/problem/1968/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n; cin >> n;
    vector <ll> v(n);
    
    for (int i = 0; i < n-1; ++i) {
        cin >> v[i];
    }
    v[n-1] = v[n-2] % ((ll) 1e9+7);

    vector <ll> a(n);
    a[0] = v[0] + 1;
    
    for (int i = 0; i < n-1; ++i) {
        a[i+1] =  v[i] + a[i] * v[i+1];
        if (a[i+1] > v[i]) a[i+1] = v[i];
        cerr << a[i+1] % a[i] << ' ';
    }
    cerr << 
    for (auto &i : a) 
        cout << i << ' '; cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}