/*
    CSES 1085 - Array Division
    https://cses.fi/problemset/task/1085
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
vector <ll> a;

bool isValid(ll x) {
    ll sum = 0, cnt = 1;
    for (auto v : a) {
        sum += v;
        if (sum > x) {
            cnt++;
            sum = v;
        } 
    }
    cerr << "x=" << x << " cnt=" << cnt << " sum=" << sum << endl;
    return cnt <= k;
}

ll bs() {
    ll l = *max_element(a.begin(), a.end()), r =1e18, mid, ans = -1;

    while (l<=r) {
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

    cin >> n >> k;
    a.resize(n);
    for (auto &e : a)
        cin >> e;

    cout << bs() << "\n";

    return 0;
}