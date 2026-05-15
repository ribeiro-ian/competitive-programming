#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;

        ll idx = 0;
        for(int i = 1; i <= n; ++i){
            ll x; cin >> x;
            idx++;

            if(x > idx){
                idx += x-idx;
            }
        }

        cout << idx-n << '\n';
    }

    return 0;
}