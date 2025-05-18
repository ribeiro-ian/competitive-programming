/*
    Beecrowd 1301 - Produto do Intervalo
    https://judge.beecrowd.com/pt/problems/view/1301
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void upd(ll i, ll v) {
    for (; i <= n; i += (i&-i))
        bit[i] += v;
}

ll sum(ll i) {
    ll ans = 0;
    for (; i > 0; i -= (i&-i))
        ans += bit[i]
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    //code

    return 0;
}