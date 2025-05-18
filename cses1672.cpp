/*
    CSES 1672 - Shortest Routes II
    https://cses.fi/problemset/task/1672
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll MAXN = 500+1, INF = 1e18;
vector <vector <ll>> d, w;
ll n, m, q, a, b, c;
 
void floyd_warshall() {
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++) {
			d[i][j] = w[i][j];
            if (i==j) d[i][j] = 0;
        }
 
	for (ll k = 1; k <= n; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m >> q; 
 
    w.assign(n+1, vector <ll> (n+1, INF));
    d.assign(n+1, vector <ll> (n+1, INF));
 
    while (m--) {
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = min(w[a][b], c);
    }
    floyd_warshall();
 
    while (q--) {
        cin >> a >> b;
 
        cout << (d[a][b] != INF ? d[a][b] : -1) << "\n";
    }
 
    return 0;
}