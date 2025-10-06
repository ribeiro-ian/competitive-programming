/*
    Codeforces 628A - Tennis Tournament
    https://codeforces.com/problemset/problem/628/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, b, p, ans = 0;
    cin >> n >> b >> p;

    int towels = n * p;
    while (n > 1) {
        int matches = n/2;
        ans += (2*b+1) * matches;
        if (n%2) {
            n = n - matches;
        }
        else {
            n /= 2;
        }
    }

    cout << ans << " " << towels << '\n';

    return 0;
}