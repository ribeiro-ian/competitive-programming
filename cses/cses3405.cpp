/*
    CSES 3405 - Sliding Window Or
    https://cses.fi/problemset/task/3405
*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll a, b, c, N = 30, curr = 0;
vector<int> bits(N);
inline ll calc(ll x) {
    return (a*x + b) % c;
}
 
void add(ll x) {
    for (ll i = 0; i < N; ++i) {
        if ((1 << i) > x) break;
 
        if (x & (1 << i))
            bits[i]++, curr |= (1LL << i);
    }
}
 
void remove(ll x) {
    for (ll i = 0; i < N; ++i) {
        if ((1 << i) > x) break;
 
        if (x & (1 << i)) {
            bits[i]--;
            if (!bits[i])
                curr -= (1LL << i);
        }
    }
}
 
ll amount() {
    ll res = 0;
    for (int i = 0; i < N; ++i) 
        if (bits[i])
            res += (1 << i);
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n, k, x;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
 
    // include first val
    ll ans, last = x;
    add(x);
    for (int i = 1; i < k; ++i) {
        x = calc(x);
        add(x);
    }
    ans = curr;
    
    for (int i = k; i < n; ++i) {
        remove(last);
        last = calc(last);
        
        x = calc(x);
        add(x);

        ans ^= curr;
    }
    cout << ans << '\n';
 
    return 0;
}