/*
    CSES 1084 - Apartments
    https://cses.fi/problemset/task/1084
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n), b(m);

    for (auto  &i : a)
        cin >> i;
    for (auto  &i : b)
        cin >> i;

    sort( a.begin(), a.end() );
    sort( b.begin(), b.end() );

    ll cnt = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (b[j] < a[i] - k) {
            j++;
        }
        else if (b[j] > a[i] + k) {
            i++;
        }
        else {
            cnt++;
            i++, j++;
        }
    }

    cout << cnt << '\n';

    return 0;
}