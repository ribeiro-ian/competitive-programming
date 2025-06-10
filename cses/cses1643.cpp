/*
    CSES 1643 - Maximum Subarray Sum
    https://cses.fi/problemset/task/1643
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d;

    cin >> n >> d;

    int pref[n+1], v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i+1] = pref[i] + v[i];
    }

    int cnt = 0;
    ll sum = 0, ans = 0;
    for (int l = 0, r = 0; l <= n; l++) {
        while (r < n && sum + pref[r] <= d) {
            sum += pref[r];
            r++;
        }

        ans = max(ans, (ll) r-l+1);
        sum -= pref[l];
    }

    cout << cnt << '\n';

    return 0;
}