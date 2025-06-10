/*
    Codeforces 1690D - Black and White Stripe
    https://codeforces.com/problemset/problem/1690/D
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    int l = 0, r = 0, cnt = 0, ans = n;
    while (r < k) {
        if (str[r] == 'W') cnt++;
        r++;
    }
    ans = min(ans, cnt);

    while (r < n) {
        if (str[l] == 'W') cnt--;
        if (str[r] == 'W') cnt++;
        r++;
        l++;
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}