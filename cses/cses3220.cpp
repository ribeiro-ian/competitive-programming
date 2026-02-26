/*
    CSES 3220 - Sliding Window Sum
    https://cses.fi/problemset/task/3220
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;
inline ll calc(ll x) {
    return (a*x + b) % c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k, x;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    
    ll ans, sum = x, last = x;
    for (int i = 1; i < k; ++i) {
        x = calc(x);
        sum += x;
    }
    ans = sum;

    for (int i = k; i < n; ++i) {
        sum -= last;
        last = calc(last);

        x = calc(x);
        sum += x;

        ans = (ans ^ sum);
    }
    cout << ans << '\n';

    return 0;
}
