/*
    Codeforces 1968C - Assembly via Remainders
    https://codeforces.com/problemset/problem/1968/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n; cin >> n;
    vector <ll> v(n-1);
    
    for (auto &i : v) {
        cin >> i;
    }

    int a = 1000;
    cout << a << ' ';
    for (int i = 0; i < n-1; ++i) {
        cerr << (a+v[i]) % a << ' ';
        a += v[i];
        cout << a << ' ';
    }
    cerr << '\n';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}