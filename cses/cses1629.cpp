/*
    CSES 1629 - Movie Festival
    https://cses.fi/problemset/task/1629
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector <pair<int,int>> v;

    for (auto &i : v) cin >> i.S >> i.F;
    // { fim, inicio }
    sort(v.begin(), v.end());

    int ini = v[0].S,
        fim = v[0].F;

    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        if (v[i+1].F <= ini) {
            ans++;
        }
        else if (v[i+1].F <= fim && v[i+1].S >= ini) {
        }
        ini = v[i+1].S;
        fim = v[i+1].F;
    }
    
    cout << ans << '\n';

    return 0;
}