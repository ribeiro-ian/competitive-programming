/*
    CSES 1076 - Sliding Window Median
    https://cses.fi/problemset/task/1076
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
multiset<ll> low, high;

void add(ll x) {
	auto aux = *low.rbegin();

	if (x > aux) {
		high.insert(x);

		if (high.size() > k / 2) {
			low.insert(*high.begin());
			high.erase(high.begin());
		}
	}
    else {
		low.insert(x);

		if (low.size() > (k + 1) / 2) {
			high.insert(*low.rbegin());
			low.erase(--low.end());
		}
	}
}

void remove(ll x) {
	if (high.find(x) != high.end())
        high.erase(high.find(x));
	else
        low.erase(low.find(x));

	if (low.empty()) {
		low.insert(*high.begin());
		high.erase(high.begin());
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    vector<ll> v(n);
    for (auto& i : v) 
        cin >> i;

    low.insert(v[0]);
    for (int i = 1; i < k; ++i) 
        add(v[i]);
    cout << *low.rbegin() << ' ';

    for (ll i = k; i < n; ++i) {
        if (k == 1) {
            add(v[i]);
            remove(v[i-k]);
        }
        else {
            remove(v[i-k]);
            add(v[i]);
        }

        cout << *low.rbegin() << ' ';
    }
    cout << '\n';

    return 0;
}