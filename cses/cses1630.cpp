/*
    CSES 1630 - Tasks and Deadlines
    https://cses.fi/problemset/task/1630
*/

#include <bits/stdc++.h>
#include <print>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, time = 0;
    cin >> n;

    vector <pll> v(n);
    for (auto &i : v) cin >> i.first >> i.second;
    
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for (auto &[t,d] : v) {
        time += t;
        
        ans += d - time;
    }

    cout << ans << '\n';

    return 0;
}