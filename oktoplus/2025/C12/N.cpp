/*
    Beecrowd 2167 - Falha do Motor
    https://judge.beecrowd.com/pt/problems/view/2167
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    vector <int> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    for (int i = 1; i < n; ++i) {
        if (v[i] < v[i-1]) {
            ans = i+1;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}