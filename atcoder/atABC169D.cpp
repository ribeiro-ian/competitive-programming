/*
    AtCoder Beginner Contest 169 - Div Game
    https://atcoder.jp/contests/abc169/tasks/abc169_d
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll ans = 0;
    for (ll p = 2; p*p <= n; ++p) {
        ll e = 0;
        while (n%p == 0) {
            e++;
            n /= p;
            cerr << n << endl;
        }

        for (ll i = 1; i <= e; ++i) {
            e -= i;
            ans++;
        }
    }
    ans += (n > 1);

    cout << ans << endl;

    return 0;
}