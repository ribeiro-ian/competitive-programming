/*
    CSES 3224 - Sliding Window Mode
    https://cses.fi/problemset/task/3224
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll,ll> cnt;
map<ll,set<ll>> freq; // key = frequency count, value = numbers with key frequency 

ll ans() {
    auto last_set = *freq.rbegin();
    return *last_set.second.begin();
}

void add(ll x) {
    ll qtt = cnt[x];

    freq[qtt].erase(x); // remove from previous freq list
    if (freq[qtt].empty()) freq.erase(qtt);
    freq[qtt+1].insert(x); // add to new freq list
    cnt[x]++;
}

void remove(ll x) {
    ll qtt = cnt[x];
    
    freq[qtt].erase(x); // remove from previous freq list
    if (freq[qtt].empty()) freq.erase(qtt);
    freq[qtt-1].insert(x); // add to new freq list
    cnt[x]--;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto& i : v) 
        cin >> i;

    // first k elements
    for (int i = 0; i < k; ++i) 
        cnt[v[i]]++;
    for (auto& [k, v] : cnt) 
        freq[v].insert(k);
    
    cout << ans() << ' ';
    for (int i = k; i < n; ++i) {
        if (v[i-k] != v[i]) {
            remove(v[i-k]);
            add(v[i]);
        }
        cout << ans() << ' ';
    }
    cout << '\n';

    return 0;
}