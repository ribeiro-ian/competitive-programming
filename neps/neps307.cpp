/*
    OBI 2008 Primeira Fase - Lanche na Empresa
    https://neps.academy/br/exercise/307
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<ll>> dist, peso;
const ll MAXN = 250+1, INF = 1e18;
ll s, c, a, b, d;

void floyd_warshall() {
    for (ll i = 1; i <= s; i++) {
        for (ll j = 1; j <= s; j++) {
            dist[i][j] = peso[i][j];
            if (i==j) dist[i][j] = 0;
        }
    }

    for (ll k = 1; k <= s; k++)
        for (ll i = 1; i <= s; i++)
            for (ll j = 1; j <= s; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> c; 

    peso.assign(s+1, vector <ll> (s+1, INF));
    dist.assign(s+1, vector <ll> (s+1, INF));

    while (c--) {
        cin >> a >> b >> d;
        peso[a][b] = peso[b][a] = min(peso[a][b], d);
    }
    floyd_warshall();

    ll ans = INF;
    for (int i = 1; i <= s; i++) {
        ll maximum = -INF;
        for (int j = 1; j <= s; j++) {
            if (dist[i][j] != INF)
                maximum = max(maximum, dist[i][j]);
        }
        ans = min(ans, maximum);
    }

    cout << ans << "\n";

    return 0;
}