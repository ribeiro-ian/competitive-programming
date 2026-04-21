/*
    Beecrowd 1046 - Tempo de Jogo
    https://judge.beecrowd.com/pt/problems/view/1046
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int ini, fim, ans;
    cin >> ini >> fim;

    if (ini == fim) {
        ans = 24;
    }
    else if (ini > fim) {
        ans = fim+24-ini;
    }
    else {
        ans = fim - ini;
    }
    cout << "O JOGO DUROU " << ans << " HORA(S)" << '\n';

    return 0;
}