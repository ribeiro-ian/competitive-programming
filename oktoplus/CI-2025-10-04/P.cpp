/*
    CSES 2183 - Missing Coin Sum
    https://cses.fi/problemset/task/2183
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    
    ll sum = 1;
    for (auto &i : v) {
        if (i > sum) {
            break;
        }
        sum += i;
    }

    cout << sum  << endl;

    return 0;
}