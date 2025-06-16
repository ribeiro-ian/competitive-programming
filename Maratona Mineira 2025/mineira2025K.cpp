/*
    Mbratona Mineira 2025K - Kubitschek
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/K
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <pii> loc(n);
    for (int i = 0; i < n; ++i) {
        cin >> loc[i].second >> loc[i].first;
    }
    sort(loc.begin(), loc.end());
    reverse(loc.begin(), loc.end());
    
    vector <pii> ans;
    for (int i = 0; i < n; ++i) {
        int posIni = loc[i].second,
            vel = loc[i].first;

        ans.push_back({posIni + i*vel, i});
    }
    
    cout << (int) ans.size() << '\n';
    for (auto &a : ans) {
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}