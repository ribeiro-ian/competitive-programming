/*
    OBI 2025 - Fase 1 - Gráfico de Barras
    https://neps.academy/br/exercise/3125
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> h(n+1);

    int tam = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        tam = max(tam, h[i]);
    }

    for (int i = 1; i <= tam; ++i) {
        for (int j = 1; j <= n; ++j) 
            cout << (tam-i < h[j] ? 1 : 0) << ' ' ;
        cout << '\n';
    }

    return 0;
}