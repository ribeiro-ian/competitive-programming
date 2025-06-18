/*
    CSES 1662 - Subarray Divisibility
    https://cses.fi/problemset/task/1662
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    vector <ll> pref(n+1);
    map <ll, ll> memo;
    memo[0] = 1;

    ll x, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        pref[i+1] = pref[i] + x;
    }
    
    for (int i = 1; i <= n; ++i) {
        cerr << pref[i] << ' ';
        cnt += memo[abs(pref[i] % n)];
        memo[pref[i]] += 1;
    }

    cerr << "resto: " << (-127 % n) << "\n";
    cout << cnt << '\n';

    return 0;
}