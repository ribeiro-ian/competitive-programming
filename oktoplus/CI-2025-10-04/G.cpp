/*
    Codeforces 2149C - MEX rose
    https://codeforces.com/problemset/problem/2149/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <bool> freq(k, 0);
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        cnt += (x==k);
        if (x < k) freq[x] = true;
    }

    ll ans = 0;
    for (auto i : freq) 
        ans += !i;
    
    cout << max(ans, cnt) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}