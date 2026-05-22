/*
 * Contest : CSES Problem Set
 * Problem : 2164 - Josephus Queries
 * Link    : https://cses.fi/problemset/task/2164
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll solve(ll n, ll k) {
	if (n == 1) return 1;
	if (k <= (n+1)/2) {
		if (2*k > n) return 2*k % n;
		else return 2*k;
	}
	
	ll kth = solve(n>>1, k - (n+1)/2);
	if (n & 1) return 2*kth + 1;
	else return 2*kth - 1;
}

int main() {
	fastio

	int tc; cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		cout << solve(n,k) << '\n';
	}

	return 0;
}