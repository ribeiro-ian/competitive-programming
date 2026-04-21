/*
    USACO 738 - Paired Up
    https://usaco.org/index.php?page=viewproblem2&cpid=738&lang=en
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, x, y;
    cin >> n;
    vector <ll> cows;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;

        while (x--)
            cows.push_back(y);
    }
    sort(cows.begin(), cows.end());
    for (auto &i : cows)
        cerr << i << " "; cerr << "\n";
    
    ll l = 0, r = cows.size()-1, ans = 0;
    while (l < r) {
        ans = max(ans, cows[l] + cows[r]);
        l++;
        r--;
    }

    cout << ans << "\n";

    return 0;
}