/*
    OBI 2013 - Segunda Fase - Troco
    https://neps.academy/br/exercise/509
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int v, m;
vector <int> moedas;

bool coin_change(int soma) {
    int n = moedas.size();   
    vector<bool> dp(soma + 1, false);

    dp[0] = true; // Caso base.
    for (int i = 0; i < n; ++i) {
        for (int j = soma; j >= moedas[i]; --j) {
            if (dp[j-moedas[i]]) dp[j] = true;
        }
    }

    return dp[soma];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> v >> m;
    moedas.resize(m);
    for (auto &i : moedas) cin >> i;
    
    cout << (coin_change(v) ? "S" : "N") << "\n";

    return 0;
}