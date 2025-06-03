/*
    Maratona Mineira 2025E - Emparelhamento
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, a, b; cin >> n;
    map <pii, ll> mapa;

    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;

        if (a != b)
            mapa[{min(a,b), max(a,b)}] += 1;
    }

    ll resto = 0, ans = 0;
    for (auto &m : mapa) {
        if (m.second % 2 == 0)
            ans += 1;
        else
            resto += 1;        
    }
    
    if (resto) ans += resto - 1;
    cout << ans << '\n';

    return 0;
}