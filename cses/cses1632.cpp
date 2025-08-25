/*
    CSES 1632 - Movie Festival II
    https://cses.fi/problemset/task/1632
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n, k;
    cin >> n >> k;

    vector <pll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) swap(v[i].second,v[i].first);
    
    ll cnt = 0;
	multiset<ll> end_times;
	for (int i = 0; i < k; ++i) end_times.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].first);
		if (it == end_times.begin()) continue;

		end_times.erase(--it);
		end_times.insert(v[i].second);

        cnt++;
	}

	cout << cnt << '\n';
 
    return 0;
}