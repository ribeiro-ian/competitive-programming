/*
    CSES 1634 - Minimizing Coins
    https://cses.fi/problemset/task/1634
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll x, n;
vector <ll> moedas;

ll coin_change(ll soma) {
    ll n = moedas.size();   
    vector<ll> dp(soma + 1, 1e9);

    dp[0] = true; // Caso base.
    for (int i = 0; i < n; ++i) {
        for (int j = moedas[i]; j <= soma; ++j) {
            if (j % moedas[i] == 0)
                dp[j] = min(dp[j], j/moedas[i]);
        }
    }

    for (int i = 0; i < dp.size(); i++)
        cerr << i << ": " << dp[i] << "\n";
    
    return dp[soma];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    moedas.resize(n);
    for (auto &i : moedas) cin >> i;
    
    cout << coin_change(x) << "\n";

    return 0;
}