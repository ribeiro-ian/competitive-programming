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

    unordered_map<ll,ll> freq;
    ll cnt = 0;
    for (ll l = 0, r = 0; r < n; ++r) {
        freq[v[r]]++;
        while (freq.size() > k) {
            freq[v[l]]--;
            if (!freq[v[l]]) freq.erase(v[l]);
            l++;
        }
        cnt += r-l+1;
    }

    cout << cnt << '\n';
    
    return 0;
}