/*
    Beecrowd 1947 - Rota do Taxista
    https://judge.beecrowd.com/pt/problems/view/1947
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 16, maxm = (1 << 15) + 10;
int n, m;
int mat[maxn][maxn], dp[maxm][maxn];
pair <int,int> tur[maxn];

int solve(int mask, int i) {
	if(mask == (1 << n) - 1) return dp[mask][i] = 0; // caso todas as cidades já tenham sido visitadas
	if(dp[mask][i] != -1) return dp[mask][i]; // se a DP ja foi calculada
	
	int ans = 1e9;
	
	for(int v = 0; v < n; v++) {
		if(mask & (1 << v) or !mat[i][v]) continue; // se a cidade atual já foi visitada ou não há rota de i à v

		ans = min(ans, solve((mask | (1 << v)), v) + mat[i][v]); //pego o minimo entre ir para cada vizinho
	}

	return dp[mask][i] = ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;

	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		mat[a][b] = mat[b][a] = c;
	}
    for (int i = 1; i <= k; ++i) {
        cin >> tur[i].first >> tur[i].second;
    }
	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << "\n"; // começando da cidade 0


}