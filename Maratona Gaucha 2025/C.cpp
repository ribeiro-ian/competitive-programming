#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n;
vector <ll> v;
void rec(ll i) {
    if (i < 0 || i >= n) return;
    ll ant = i-1, prox = i+1;
    if (ant < 0) ant = n-1;
    if (prox >= n) prox = 0;
    
    rec(ant);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) 
    cin >> v[i];
    
    for (int i = 0; i < n; i++) 
        rec(i);
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(v[i], ans);
    } 
    cout << ans << '\n';
    
    cerr << '\n';
    for (int i = 0; i < n; i++) {
        cerr << v[i] << ' ';
    }
    cerr << '\n';
    
    return 0;
}