/*
    CSES 3420 - Distinct Values Subarrays
    https://cses.fi/problemset/task/3420
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) cin >> i;
    set <ll> s;

    ll cnt = 0;
    for (int l = 0, r = 0; l < n;) {
        while (r < n) {
            if (s.count(v[r])) 
                break;
            
            s.insert(v[r]);
            r++;
        }
        
        cnt += r-l;
        s.erase(v[l]);
        l++;
    }

    cout << cnt << '\n';


    return 0;
}