/*
    Beecrowd 3351 - Clickbait
    https://judge.beecrowd.com/pt/problems/view/3351
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> v;
ll n, k;

bool valid(ll x){
    ll cnt = 0;
    for(auto& [a, b] : v){
        if(a <= x) cnt += 1 + (x-a)/b;
        
        if(cnt >= k) return true;
    }
    return false;
}

ll bs(){
    ll l = 1, r = 2e18+1;

    while(l <= r){
        ll m = l + (r-l)/2;

        if(valid(m))
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    v.resize(n);
    for(auto& [a,b] : v) cin >> a >> b;

    cout << bs() << '\n';

    return 0;
}