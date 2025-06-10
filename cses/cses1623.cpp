/*
    CSES 1623 - Apple Division
    https://cses.fi/problemset/task/1623
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ans = 1e18, w, total, n;
vector <ll> v;

void search(int i) {
    if (i >= n) {
        ll w2 = total - w;
        ans = min(ans, abs(w - w2));
    }
    else {
        w += v[i];
        search(i+1);

        w -= v[i];
        search(i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    v.resize(n);
    total = 0, w = 0;
    for (auto &i : v) {
        cin >> i;
        total += i;
    }
    
    search(0);

    cout << ans << '\n';

    return 0;
}