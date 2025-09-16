#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define srt(x) sort(all(x));
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define f0r(x) for(int i = 0; i < x; i++)

typedef long long ll;
typedef long double ld;



int main(){

    int n; cin >> n;   

    vector<pair<ll, ll>> vet(n);
    map<ll, pair<ll, ll>> mapa;

    f0r(n){
        cin >> vet[i].F >> vet[i].S; 
        if(mapa.find(vet[i].F) != mapa.end()){
            mapa[vet[i].F].F = min(mapa[vet[i].F].F, vet[i].S);
            mapa[vet[i].F].S = max(mapa[vet[i].F].S, vet[i].S);
        }
        else {
            mapa[vet[i].F].F = vet[i].S;
            mapa[vet[i].F].S = vet[i].S;
        }
    }

    map<ll, ll> media;
    for(auto &m : mapa){
        cerr << m.F << " : ";
        cerr << m.S.F << " ";
        cerr << m.S.S << " ";
        media[m.F] = (m.S.F + m.S.S)/2;
    }
    cerr << endl;

    ll ans = 0;
    f0r(n){
        ans += abs(vet[i].S - media[vet[i].F]);
    }

    cout << ans << endl;

    return 0;
}