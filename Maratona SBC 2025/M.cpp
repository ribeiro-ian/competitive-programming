#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k;
vector <ll> v;

bool isValid(ll x) {
    //s = n*(n+1)/2;
    
}

ll bs() {
    ll l = 1, r = *max_element(v.begin(),v.end())+k, m, ans = 1;

    while (l <= r) {
        m = l + (r-l)/2;

        if (isValid(m)) {
            l = m+1;
            ans = m;
        }
        else {
            r = m-1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v) cin >> i;

    cout << bs() << '\n';

    return 0;
}