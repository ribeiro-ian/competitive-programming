/*
    Beecrowd 2832 - Cápsulas
    https://judge.beecrowd.com/pt/problems/view/2832
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, f;
vector <ll> cycles;

bool isValid(ll x) {
    ll cnt = 0;
    for (auto c : cycles) 
        cnt += x / c;

    cerr << "mid = " << x << " cnt = " << cnt << "\n";
    return cnt >= f;
}

ll bs() {
    ll l = 1, r = 1e18, m, ans = -1;

    while (l <= r) {
        m = l + (r-l)/2;

        if (isValid(m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> f;
    cycles.resize(n);
    for (auto &i : cycles)
        cin >> i;

    cout << bs() << "\n";

    return 0;
}