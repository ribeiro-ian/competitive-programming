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
    
    x++, y++;
    cout << max(y, b-y) * a << " ";
    cout << max(x, a-x) * b << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}