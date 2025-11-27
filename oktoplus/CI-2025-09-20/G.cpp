#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ll solve(ll x) {
    ll cnt = 0;

    for (int i = 2; i*i <= x; ++i) {
        cnt += x / (i*i);
    }

    return x + cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t, n; cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}