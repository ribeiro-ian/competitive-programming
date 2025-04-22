/*
    Codeforces 1315A - Dead Pixel
    https://codeforces.com/problemset/problem/1315/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    
    cout << max(max(x,a - 1 - x)*b, max(y,b - 1 - y) * a) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}