/*
    Beecrowd 1261 - Pontos de Feno
    https://judge.beecrowd.com/pt/problems/view/1261
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
void solve(){
    map<string, ll> mp;
    while(m--){
        string s; ll x;
        cin >> s >> x;
        mp[s] = x;
    }

    string word;
    while(n--){
        ll sum = 0;
        while(cin >> word, word != ".") 
            sum += mp[word];
        cout << sum << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> m >> n) solve();

    return 0;
}