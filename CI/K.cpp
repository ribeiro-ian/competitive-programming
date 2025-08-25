#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll MAXN = 1e5;    
    vector <ll> memo (MAXN, 0);
    memo[1] = 2;
    memo[2] = 7;
    for (int i = 3; i < MAXN; ++i) {
        memo[i] = memo[i-1] + (i-1) + (i*2);
    }

    ll tc; cin >> tc;
    while (tc--) {
        ll x; cin >> x;
        
        ll ans;
        auto it = upper_bound(memo.begin(), memo.end(), x);
        it--;
        ans = (ll) distance(memo.begin(), it);

        cout << ans << '\n';
    }

    return 0;
}