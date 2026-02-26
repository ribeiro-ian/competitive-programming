/*
    OBI 2015 - Segunda Fase - Código
    https://neps.academy/br/exercise/47
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, atual, prox, terceiro, cont = 0;
    
    cin >> n >> atual >> prox >> terceiro;
    if (atual == 1 && prox == 0 && terceiro == 0)
        cont++;

    for (int i = 3; i < n; ++i) {
        atual = prox;
        prox = terceiro;
        
        cin >> terceiro;

        if (atual == 1 && prox == 0 && terceiro == 0)
            cont++;
    }
    cout << cont << '\n';

    return 0;
}