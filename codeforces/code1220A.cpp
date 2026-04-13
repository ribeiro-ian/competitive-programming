/*
    Codeforces 1220A - Cards
    https://codeforces.com/problemset/problem/1220/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int nCnt = 0, zCnt = 0;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (c == 'n')
            nCnt++;
        if (c == 'z')
            zCnt++;
    }
    while (nCnt--)
        cout << "1 ";
    while (zCnt--)
        cout << "0 ";
    cout << '\n';

    return 0;
}