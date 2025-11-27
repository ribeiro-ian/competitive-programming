/*
    Codeforces 2162C - Beautiful XOR
    https://codeforces.com/contest/2162/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    cerr << '\n';
    ll a, b;
    cin >> a >> b;

    if (a==b) {
        cout << "0\n";
        return;
    }
    if ((ll) log2(b) > (ll) log2(a)) {
        cout << "-1\n";
        return;
    }
    vector <ll> ans;
    while (a != b) {
        ll x = 0;

        for (int i = 0; i <= a; i++) {
            ll y = (1<<i);
            if (x+y > a) break;

            // bit i of B should be on
            if (b & y) {
                // bit i of A is off => add bit i
                if (!(a & y)) x += y;
            }
            // bit i is off 
            else {
                // bit i of A is on => add bit i
                if (a & y) x += y;
            }
        }
        ans.push_back(x);
        a = a ^ x;
    }

    cout << (int) ans.size() << '\n';
    for (auto &i : ans)
    cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}