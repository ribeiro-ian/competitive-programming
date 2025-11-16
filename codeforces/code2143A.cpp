/*
    Codeforces 2143A - All Lengths Subtraction
    https://codeforces.com/contest/2143/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool solve() {
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) {
        cin >> i;
        if (i==n) i--;
    }

    ll k = 2;
    while (k <= n) {
        ll cnt = 1, last = 0;
        for (int i = 0; i < n-1; ++i) {
            if (v[i] == v[i+1] && v[i] == n-k+1) {
                v[i]--;
                cnt++;
                last = i+1;
            }
        }
        v[last]--;

        if (cnt != k) return false;
        k++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << '\n';

    return 0;
}