/*
    Codeforces 1840C - Ski Resort
    https://codeforces.com/problemset/problem/1840/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, k, q;

    cin >> n >> k >> q;
    
    int a[n];
    for (auto &e : a)
        cin >> e;

    int cnt = 0;
    for (int l=0, r=0; l < n-k; l++) {
        while (r < n && a[r] <= q) {
            r++;
        }
        int len = r-l;
        if (len >= k)
            cnt += (len - k + 1) * (len - k + 2) / 2;
        r = max(r,l);
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}