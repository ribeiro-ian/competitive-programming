/*
    CSES 1618 - Trailing Zeros
    https://cses.fi/problemset/task/1618
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    int cnt = 0;
    for (int i = 5; n/i >= 1; i*=5) {
        cnt += n/i;
    }

    cout << cnt << '\n';

    return 0;
}