#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, m, k; 

bool valid(ll x) {
    ll cnt = x, r = k+1, l = k-1, value = x-1;
    while (r <= n) {
        cnt += value;
        value = max(1LL, value-1);
        r++;
    }

    value = x-1;
    while (l >= 1) {
        cnt += value;
        value = max(1LL, value-1);
        l--;
    }
    cerr << "x: " << x << "; cnt: " << cnt << "\n";
    return cnt <= m;
}

ll bs() {
    ll l = 1, r = m, ans = -1, mid;

    while (l <= r) {
        mid = l+(r-l)/2;

        if (valid(mid)) {
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