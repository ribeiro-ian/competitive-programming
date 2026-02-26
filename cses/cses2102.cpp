/*
    CSES 2102 - Finding Patterns
    https://cses.fi/problemset/task/2102
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>, int>> suffix;
string s, p;

void build() {
    s += '$';
    int n = s.size();

    suffix.resize(n);
    for (int i = 0; i < n; ++i) 
        suffix[i] = {{s[i], s[i]}, i};
    sort(suffix.begin(), suffix.end());
    
    vector<int> equiv(n);
	for (int i = 1; i < n; i++) {
		auto [c_val, cs] = suffix[i];
		auto [p_val, ps] = suffix[i - 1];
		equiv[cs] = equiv[ps] + (c_val > p_val);
	}
    
    for (int k = 1; k < n; k *= 2) {
		for (auto &[val, s] : suffix) 
        // the order numbers for the left half and right half respectively
			val = {equiv[s], equiv[(s + k) % n]};
            
        sort(suffix.begin(), suffix.end());
        
		// assign numbers to the newly sorted suffixes
		for (int i = 1; i < n; i++) {
			auto [c_val, cs] = suffix[i];
			auto [p_val, ps] = suffix[i - 1];
			equiv[cs] = equiv[ps] + (c_val > p_val);
		}
	}
}

int search(int i = 0) {
    int l = 1, r = suffix.size(), m;

    while (l <= r) {
        m = l + (r-l)/2;

        cerr << "m = " << m << " | " << suffix[m].second << " | " << s[suffix[m].second + i] <<'\n';
        if (s[suffix[m].second + i] < p[i])
            l = m + 1;
        else
            r = m - 1;
    }


    cerr << suffix[m].first.first << ' ' << suffix[m].first.second <<'\n';

    if (s[suffix[m].second + i] != p[i]) return -1;
    ++i;
    
    if (i == p.size())
        return 1;
    return m;
    // else
    //     return search(i+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    build();
    int k; cin >> k;

    for (int i = 1; i < suffix.size(); ++i) 
        cerr<< suffix[i].second << " ! " << s.substr(suffix[i].second) << '\n';
        cerr << "\n\n";
    

    while (k--) {
        cin >> p;
        cout << search() << '\n';
    }

    return 0;
}