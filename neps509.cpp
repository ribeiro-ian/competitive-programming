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

int coin_change(int soma) {
    int n = moedas.size();   
    
    // dp[i] guarda a quantidade de maneiras de se obter o valor i
    vector<int> dp(soma + 1);

    dp[0] = 1; // Caso base.
    for (int i = 0; i < n; ++i) {
        for (int j = moedas[i]; j <= soma; ++j) {
            dp[j] += dp[j -  moedas[i]];
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