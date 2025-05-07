/*
    Codeforces 760B - Frodo and pillows
    https://codeforces.com/problemset/problem/760/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, m, k; 

ll f(ll len, ll x) {
    x--;
    ll first = max(1LL, x-len+1), last = x, ret = 0;

    if (len > x) {
        ret += len-x;
    }
    ret += (first + last) * (last - first + 1)/2;

    return ret;
}

bool isValid(ll x) {
    ll l = k-1, r = n-k;

    ll cnt = x + f(l, x) + f(r, x);

    return cnt <= m;
}

ll bs() {
    ll l = 1, r = m, ans = -1, mid;

    while (l <= r) {
        mid = l+(r-l)/2;

        if (isValid(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    cout << bs() << "\n";

    return 0;
}