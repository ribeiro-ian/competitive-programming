/*
    CSES 2185 - Prime Multiples
    https://cses.fi/problemset/task/2185
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k, cnt = 0;
    cin >> n >> k;
    vector <ll> p(k);
    for (auto &i : p) {
        cin >> i;
        cnt += n/i;
    }

    for (int i = 0; i < k-1; ++i) {
        for (int j = i+1; j < k; ++j) {
            if (i==j) continue;
            cnt -= n/(p[i]*p[j]);
        }
    }
    2 3 5 7 11 13 17 19

    cout << cnt << '\n';

    return 0;
}