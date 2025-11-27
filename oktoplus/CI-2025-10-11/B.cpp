/*
    CSES 1646 - Static Range Sum Queries
    https://cses.fi/problemset/task/1646
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q;
    cin >> n >> q;
    vector <ll> pref(n+1);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pref[i+1] = pref[i] + x;
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a-1] << '\n';
    }

    return 0;
}