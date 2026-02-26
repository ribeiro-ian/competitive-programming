/*
    CSES 2080 - Fixed-Length Paths I
    https://cses.fi/problemset/task/2080
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+1;
vector<ll> graph[N], subSize(N), done(N);
ll ans = 0, n, k, max_d = 0, cnt[N]{1};

ll getSubSize(ll u = 1, ll p = -1) {
    subSize[u] = 1;
    for (auto& v : graph[u]) {
        if (v == p || done[v]) continue;

        subSize[u] += getSubSize(v, u);
    }
    return subSize[u];
}

ll get_centroid(ll target, ll u = 1, ll p = -1) {
	for (auto& v : graph[u]) {
		if (v == p || done[v]) continue;

        if (subSize[v] >= target)
            return get_centroid(target, v, u);
	}
	return u;
}

void get_cnt(ll u, ll p, bool filling, ll d = 1) {
	if (d > k) return;
	max_d = max(max_d, d);

	if (filling) cnt[d]++;
	else ans += cnt[k - d];

	for (auto& v : graph[u])
		if (!done[v] && v != p) get_cnt(v, u, filling, d + 1);

}

void solve(ll no = 1) {
	ll centroid = get_centroid(getSubSize(no) / 2, no);
	done[centroid] = true;

	max_d = 0;
	for (auto& v : graph[centroid])
		if (!done[v]) {
			get_cnt(v, centroid, false);
			get_cnt(v, centroid, true);
		}

    fill(cnt+1, cnt+1+max_d, 0);
	for (auto& v : graph[centroid])
		if (!done[v]) solve(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (ll i = 1; i < n; ++i) {
        ll a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve();    
    cout << ans << '\n';
    
    return 0;
}