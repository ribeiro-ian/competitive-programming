/*
    CSES 2205 - Gray Code
    https://cses.fi/problemset/task/2205
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int N = 16;
    ll n; cin >> n;

    ll num = 1;
    cout << b.to_string().substr(N-n,N) << '\n';

    if (n <= 1) return 0;
    while (num < (ll) pow(2,n)) {
        bitset <N> b (num);

        cerr << num << ": ";
        cout << b.to_string().substr(N-n,N) << '\n';

        num++;
    }

    return 0;
}