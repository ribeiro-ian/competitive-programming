/*
    CSES 2431 - Digit Queries
    https://cses.fi/problemset/task/2431
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll fast_power(ll a, ll b) { 
    ll res = 1;

    while (b > 0) {
        if (b % 2 == 1) res *= a; // res = res * a % m
        a *= a; // a = a * a % m;
        b /= 2;
    }
    return res;
}


ll solve(ll n) {
    ll digits = 1,
       base = 9;

    while (n - digits * base > 0) {
        n -= digits * base;
        base *= 10;
        digits++;
    }

    ll idx = n % digits;
    ll res = fast_power(10, digits-1) + (n-1)/digits;
    cerr << res << '\n';
    
    if (idx)
        res = res / fast_power(10, digits-idx); 
    
    return res%10;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t, k;
    cin >> t;
    while (t--) {
        cin >> k;

        cout << solve(k) << '\n';
    }

    return 0;
}