/*
    CSES 2428 - Distinct Values Subarrays II
    https://cses.fi/problemset/task/2428
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    for (auto &i : v) cin >> i;
    multiset <ll> ms;
    set <ll> s;

    ll cnt = 0;
    for (ll l = 0, r = 0; l < n; l++) {
        while (r < n) {
            if ((ll) s.size() > k) 
                break;
            if ((ll) s.size() <= k) cnt++;
            s.insert(v[r]);
            ms.insert(v[r]);
            r++;
        }
        
        ms.erase(ms.find(v[l]));
        if (!ms.count(v[l])) s.erase(v[l]);

        if ((ll) s.size() <= k) cnt++;
    }

    cout << cnt << '\n';


    return 0;
}