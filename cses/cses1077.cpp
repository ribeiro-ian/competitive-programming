/*
    CSES 1077 - Sliding Window Cost
    https://cses.fi/problemset/task/1077
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
multiset<ll> low, high;
ll sumLow, sumHigh;

void add(ll x) {
	auto aux = *low.rbegin();

	if (x > aux) {
		high.insert(x);
        sumHigh += x;
        
		if (high.size() > k / 2) {
            ll y = *high.begin();
            low.insert(y);
            sumLow += y;
            
			high.erase(high.begin());
            sumHigh -= y;
		}
	}
    else {
        low.insert(x);
        sumLow += x;

		if (low.size() > (k + 1) / 2) {
            ll y = *low.rbegin();
			high.insert(y);
            sumHigh += y;
            
			low.erase(--low.end());
            sumLow -= y;
		}
	}
}

void remove(ll x) {
	if (high.find(x) != high.end())
        high.erase(high.find(x)), sumHigh -= x;
	else
        low.erase(low.find(x)), sumLow -= x;

	if (low.empty()) {
        ll y = *high.begin();
		low.insert(y);
        sumLow += y;

		high.erase(high.begin());
        sumHigh -= y;
	}
}

ll ans() {
    ll median = (k % 2 ? *low.rbegin() : 0);
    return sumHigh - sumLow + median;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    vector<ll> v(n);
    for (auto& i : v) 
        cin >> i;

    low.insert(v[0]); sumLow += v[0];
    
    for (int i = 1; i < k; ++i) 
        add(v[i]);
    cout << ans() << ' ';

    for (ll i = k; i < n; ++i) {
        if (k == 1) {
            add(v[i]);
            remove(v[i-k]);
        }
        else {
            remove(v[i-k]);
            add(v[i]);
        }

        cout << ans() << ' ';
    }
    cout << '\n';

    return 0;
}