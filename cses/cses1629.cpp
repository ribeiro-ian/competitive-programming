/*
    CSES 1629 - Movie Festival
    https://cses.fi/problemset/task/1629
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n; cin >> n;
 
    vector <pair <ll,ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
 
    ll curr = v[0].first, cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i].second >= curr) {
            curr = v[i].first;
            cnt++;
        }
    }
 
    cout << cnt << '\n';
 
    return 0;
}