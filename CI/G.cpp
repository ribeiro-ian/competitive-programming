#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, c, t, total = 0, maior;
vector <ll> v;

bool isValid(ll x) {
    ll sum = 0, cnt = 1;
    for (auto &i : v) {
        sum += i;
        if (sum > x) {
            cnt++;
            sum = i;
        } 
    }
    return cnt <= c;
}

ll bs() {
    ll l = maior, r = total, mid, ans;

    while (l <= r) {
        mid = l+(r-l)/2;

        if (isValid(mid)) {
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

    cin >> n >> c >> t;
    v.resize(n);
    maior = 0;
    for (auto &i : v) {
        cin >> i;
        total += i;
        maior = max(maior, i);
    }

    ll res = bs();
    ll ans = res / t;
    if (res % t) ans++;
    cout << ans << '\n';

    return 0;
}