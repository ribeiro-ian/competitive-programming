/*
    CSES 1091 - Concert Tickets
    https://cses.fi/problemset/task/1091
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, t;

ll bs(vector <ll> &v, ll x) {
    ll l = 0, r = n-1, m;

    while (l <= r) {
        m = l+(r-l)/2;
        if (v[m] > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    vector <ll> v(n);    

    for (auto &i : v) cin >> i;
    
    sort(v.begin(), v.end());
    for (auto &i : v) cerr << i << ' '; cerr << '\n';
    while (k--) {
        cin >> t;
        ll ans = bs(v, t);
        cout << (ans != -1 ? v[ans] : ans) << '\n';
        if (ans >= 0) v.erase(v.begin() + ans);
    }

    return 0;
}