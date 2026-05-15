/*
    Beecrowd 1290 - Caixas Muito Especiais
    https://judge.beecrowd.com/pt/problems/view/1290
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
void sortDim(ll& x, ll& y, ll& z){
    ll a[3] = {x, y, z};
    sort(a, a+3);
    x = a[0]; y = a[1]; z = a[2];
}

void solve(){
    if(!n) return;
    
    ll x, y, z, vol;
    cin >> x >> y >> z;
    sortDim(x,y,z);
    vol = x*y*z;
    
    map<vector<ll>,ll> freq;
    for(ll i = 0; i < m; ++i){
        ll cx,cy,cz;
        cin >> cx >> cy >> cz;
        sortDim(cx,cy,cz);
        freq[{cx,cy,cz}]++;
    }

    ll ans = 1e18;
    for(auto& [d, cnt] : freq){
        if(cnt < n) continue;
        auto cx = d[0], cy = d[1], cz = d[2];
        auto cvol = cx*cy*cz;

        if(x <= cx && y <= cy && z <= cz){
            ans = min(ans, cvol - vol);
        }
    }
    if(ans == 1e18)
        cout << "impossible\n";
    else
        cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> m)
        solve();

    return 0;
}