/*
    OBI 2025 - Fase 2 - Feira de Artesanato
    https://neps.academy/br/exercise/3266
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 1e5+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, t, x;
    cin >> n >> t;

    vector<ll> id(n);
    for(auto& i : id) 
        cin >> i;
    
    vector<multiset<ll>> types(t+1);
    multiset<pair<ll,ll>> all;
    for(int i = 0; i < n; ++i){
        cin >> x;
        types[id[i]].insert(x);
        all.insert({x, id[i]});
    }

    int c; cin >> c;
    ll ans = 0;
    while(c--){
        cin >> x;

        if(x == 0){
            if(!all.empty()){
                auto p = *all.begin();
                ll price = p.first,
                   type = p.second;
                   
                ans += price;
                all.erase(all.begin());
                
                auto& ms = types[type];
                ms.erase(ms.begin());
            }
        }
        else {
            auto& ms = types[x];
            if(!ms.empty()){
                ll price = *ms.begin();

                ans += price;
                all.erase(all.find({price, x}));
                ms.erase(ms.begin());
            }
        } 
    }
    cout << ans << '\n';
        
    return 0;
}