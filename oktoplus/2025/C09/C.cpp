/*
    CSES 1620 - Factory Machines
    https://cses.fi/problemset/task/1620
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, t;
vector <ll> v;

ll f(int x) {
    ll ret = 0;
    for (auto &i : v) {
        ret += x/i;
    }
    return ret;
}

ll bs() {
    ll l = 0, r = INT_MAX, mid, ans = 0;

    while (l <= r) {
        mid = (l+r)/2;

        if (f(mid) >= t) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    v.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    cout << bs() << '\n';
    cerr << f(bs()) << '\n';

    return 0;
}