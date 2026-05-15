/*
    Beecrowd 1800 - Onde Estão Minhas Chaves
    https://judge.beecrowd.com/pt/problems/view/1800
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q, e;
    cin >> q >> e;
    
    set<int> esteve;
    while(e--){
        int x; cin >> x;
        esteve.insert(x);
    }
    while(q--){
        int x; cin >> x;
        cout << !(esteve.count(x)) << '\n';
        esteve.insert(x);
    }

    return 0;
}