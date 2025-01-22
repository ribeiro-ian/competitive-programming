#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull MOD = 1e9 + 7;
ull power(ull base, ull expo) {
    ull ans = 1;
    while(expo) {
        // if(expo % 1LL)
            // se for impar, binario terminar em 1, pois 1 & 1 == 1 (V & V), logo procede pro if
            // se for par, 0 & 1 = 0 (F & V = F)
        if(expo % 2)
            ans = (ans * base) % MOD;
        
        base = (base * base) % MOD;
        // expo >>= 1LL; // dividir por 2 ^ 1 (expo = expo >> 1LL)
        expo /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n; cin >> n;
    cout << power(2LL, n) % MOD << endl;

    return 0;
}
