/*
    CSES 1094 - Increasing Array
    https://cses.fi/problemset/task/1094
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll v[n];
 
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
    ll cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i-1]) {
            ll aux = abs(v[i] - v[i-1]);
            cnt += aux;
            v[i] += aux;
        }
    }

    cout << cnt << '\n';

    return 0;
}