/*
    CSES 1094 - Increasing Array
    https://cses.fi/problemset/task/1094
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll v[n];
 
    for(int i = 0; i < n; i++)
        cin >> v[i];
 
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]){
            ll aux = abs(v[i] - v[i-1]);
            ans += aux;
            v[i] += aux;
        }
    }

    cout << ans << '\n';

    return 0;
}