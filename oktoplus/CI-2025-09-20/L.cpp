#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+5;
ll tab[MAXN][25];

int query(int l, int r) {
	int k = (int) log2(r-l + 1);

	return max(tab[l][k], tab[r - (1<<k) + 1][k]);
}

void solve() {
    int n; cin >> n;
    ll v[n+1];

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
	for (int i = 0; i < n; i++)
		tab[i][0] = v[i];

    for (int j = 1; (1 << j) <= (int) log2(n); ++j)
	    for (int i = 0; (i + (1 << j) - 1) < n; i++)
            tab[i][j] = max(tab[i][j-1], tab[i + (1 << (j - 1))][j-1]);

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l-1, r-1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}