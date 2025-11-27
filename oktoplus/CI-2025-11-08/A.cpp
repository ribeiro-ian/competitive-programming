#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, sum = 0;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto &i : v) {
        cin >> i;
        sum += i;
    }

    // cout << abs(v[0] - v[1]) << ' ';
    for (int i = 1; i < n; ++i) {
        if (i==n-1)
            cout << abs(v[i] - v[i-1]);
        else 
            cout << max(abs(v[i] - v[i-1]), abs(v[i] - v[i+1]));
        cout << ' ';
    }
    cout << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}