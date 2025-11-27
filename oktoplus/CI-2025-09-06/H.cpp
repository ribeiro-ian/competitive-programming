#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector <ll> v(n);
        for (auto &i : v) cin >> i;
        sort(v.begin(), v.end(), greater<ll>());
        
        ll sum = 0, ans = k;
        for (int i = 0; i < n; ++i) {
            sum += v[i];
            if (sum > k) break;
            
            ans = min(k-sum, ans);
        }
        cout << ans << '\n';
    }

    return 0;
}