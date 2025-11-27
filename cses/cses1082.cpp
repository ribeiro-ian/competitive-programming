/*
    CSES 1082 - Sum of Divisors
    https://cses.fi/problemset/task/1082
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
constexpr ll M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll ans = 1;

    vector <ll> num(sqrt(n), 1);
    for (ll i = 2; i*i < n; ++i) {
        if (i != num[i]) {
            ll j = i;
            while (j < num.size()) {
                num[j] *= j/i + 1;
                j += i; 
            }
        }
    }

    cout << ans << '\n';

    return 0;
}