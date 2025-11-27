/*
    CSES 3421 - Distinct Values Subsequences
    https://cses.fi/problemset/task/3421
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, mod = 1e9+7;
    cin >> n;
    unordered_map <ll,ll> freq; // O(1) operations

    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        freq[x]++;
    }
    
    ll ans = 1;
    for (auto &[num, cnt] : freq)
        ans = (ans * (cnt+1)) % mod;

    cout << ans-1 << '\n';

    return 0;
}