/*
    Codeforces 550B - Preparing Olympiad
    https://codeforces.com/problemset/problem/550/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, l, r, x, cnt = 0;
    cin >> n >> l >> r >> x;

    vector <ll> v(n);
    for (auto &i : v) cin >> i;

    for (int mask = 0; mask <= (1 << n)-1; ++mask) {
        ll s = 0, high = 0, low = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                s += v[i];
                low = min(low, v[i]);
                high = max(high, v[i]);
            }
        }

        if (s >= l && s <= r && high - low >= x) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}