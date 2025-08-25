#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll converter(string temp){
    ll min = 0, seg = 0, mile = 0;

    if(temp[1] == ':'){
        min = (temp[0] - '0');
        seg = (((temp[2] - '0')*10) + (temp[3] - '0'));
        mile = (((temp[5] - '0')*100) + ((temp[6] - '0')*10) + (temp[7] - '0'));
    }
    else if(temp[2] == ':'){
        min = (((temp[0] - '0')*10) + (temp[1] - '0'));
        seg = (((temp[3] - '0')*10) + (temp[4] - '0'));
        mile = (((temp[6] - '0')*100) + ((temp[7] - '0')*10) + (temp[8] - '0'));
    }

    return (min*60000 + seg*1000 + mile);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map <ll, vector <ll>> pilotos;
    vector <pair<ll, ll>> total;
    ll n, v, p;
    cin >> n >> v;
    
    ll menorVolta = 1e18, menorNumVolta = v+1;
    for (ll i = 0; i < n; ++i) {
        cin >> p;

        pilotos[p].resize(v);

        ll sum = 0;
        for (ll j = 0; j < v; ++j) {
            string tempo; cin >> tempo;
            ll t = converter(tempo);

            menorVolta = min(menorVolta, t);
            
            pilotos[p][j] = t;
            sum += t;
        }
        total.push_back( {sum, p} );
    }

    sort(total.begin(), total.end());

    // pegar menorVolta tempo
    vector <ll> ans;

    for (ll j = 0; j < 10; ++j) {
        ll p = total[j].second, idx = -1;

        for (ll i = 0; i < v; ++i) {
            if (pilotos[p][i] == menorVolta){
                idx = i;
                break;
            }
        }
        if (idx == -1) continue;

        if (idx < menorNumVolta) {
            menorNumVolta = idx;
            ans.clear();
        }
        if (idx == menorNumVolta) {
            ans.push_back(p);
        }
    }

    if ((ll) ans.size() == 1) {
        cout << ans[0] << '\n';
    }
    else {
        cout << "NENHUM\n";
    }
    
    return 0;
}