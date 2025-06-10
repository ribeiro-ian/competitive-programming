/*
    Codeforces 2091D - Place of the Olympiad
    https://codeforces.com/contest/2091/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll tc, n, m, k;
 
ll f(ll x) {
    return n * (x * (m/(x+1)) + m % (x+1));
}

ll bs() {
    ll l = 1, r = m, mid, ans = -1;

    while (l <= r) {
        mid = l+(r-l)/2;

        fprintf(stderr, "f(%lli) = %lli\n", mid, f(mid));

        if (f(mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> k;

        cout << bs() << '\n';
        cerr << "----------------\n";
    }
    

    return 0;
}