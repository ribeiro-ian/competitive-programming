/*
    Beecrowd 1661 - Comércio de Vinhos na Gergóvia
    https://judge.beecrowd.com/pt/problems/view/1661
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ll n, v[112345];

    while (scanf("%lli", &n)) {
        if (!n) break;

        for (int i = 0; i < n; i++) 
            scanf("%lli\n", v[i]);
        
        ll amount = v[0], ans = 0;
        for (int i = 1; i < n; i++) {
            amount += min(amount, abs(v[i]));
            amount -= v[i];
        }
        
        // 4 + 3 + 1 + 1
    }


    return 0;
}
