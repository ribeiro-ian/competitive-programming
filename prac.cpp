#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool is_computed[112345];
ll f[112345];

ll fib_dp(ll x) {
    if (x < 2) return f[x] = x;

    if (is_computed[x]) return f[x];

    f[x] = fib_dp(x-1) + fib_dp(x-2);
    is_computed[x] = true;
    return f[x];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // Recursive DP
    ll x; cin >> x;
    cout << fib_dp(x) << endl;
    
    for (int i = 1; i <= x; i++){
        cerr << f[i] << " ";
    } cerr << "\n";

    // Iterative DP
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= x; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    
    return 0;
}