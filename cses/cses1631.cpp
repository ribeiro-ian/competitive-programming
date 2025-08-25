/*
    CSES 1631 - Reading Books
    https://cses.fi/problemset/task/1631
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, sum = 0; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) {
        cin >> i;
        sum += i;
    }

    sort(v.begin(), v.end());

    if (v[n-1] > sum - v[n-1]) {
        cout << v[n-1] * 2 << '\n';
    }
    else {
        cout << sum << '\n';
    }

    return 0;
}