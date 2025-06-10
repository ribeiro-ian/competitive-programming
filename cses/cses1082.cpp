/*
    CSES 1082 - Sum of Divisors
    https://cses.fi/problemset/task/1082
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9+7;

ll divisorSum(ll num) {
    ll sum = 0;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum = ((sum % MOD) + (i % MOD)) % MOD;
            if (i*i != n) {
                sum = ((sum % MOD) + (n/i % MOD)) % MOD;
            }
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x; cin >> x;
    cout << divisorSum(x) << "\n";

    return 0;
}