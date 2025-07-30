#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> v(n);
    map <ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());

    if (mp[v[n-1]] == 1) {
        cout << v[n-1] << '\n';
        return 0;
    }
    else if (mp[v[n-1]] == n) {
        cout << v[n-1] * 2 << '\n';
        return 0;
    }

    ll l = 0, r = 0;
    while (v[r] < v[n-1]) {
        r++;
    }

    ll ans = 1e18;
    while (l < r) {
        ll sum = v[l] + v[r];

        if (sum > v[n-1]) {
            r--;
            ans = min(ans, sum);
        }
        else if (sum < v[n-1]) {
            l++;
        }
        else {
            l++;
        }
    }

    cout << ans << '\n';
    
    return 0;
}