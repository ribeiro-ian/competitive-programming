/*
    Codeforces 101845C - Cryptography
    https://codeforces.com/gym/101845/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll N = 126-33+1, INF = 1e18;
vector <vector <ll>> dist(N,vector<ll>(N,INF)), peso(N,vector<ll>(N,INF));

void floyd_warshall() {
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            dist[i][j] = peso[i][j];
            if (i==j) dist[i][j] = 0;
        }
    }

    for (ll k = 0; k < N; ++k)
        for (ll i = 0; i < N; ++i)
            for (ll j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s, t;
    cin >> s >> t;

    int m; cin >> m;

    while (m--) {
        char a, b; ll c;
        cin >> a >> b >> c;
        peso[a-33][b-33] = min(peso[a-33][b-33],c);
    }

    floyd_warshall();
    ll ans = 0;
    bool flag = true;
    cerr << dist['o'-33]['d'-33] << "\n";

    for (int i = 0; i < s.size(); ++i) {
        ll d = dist[ s[i] - 33 ][ t[i] - 33 ];

        if (d == INF) {
            flag = false;
            break;
        }
        else
            ans += d;
    }

    cout << (flag ? ans : -1) << "\n";
    cerr << "ans = " <<  ans << endl;

    return 0;
}