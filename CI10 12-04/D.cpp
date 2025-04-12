/*
    Codeforces 1462A - Favorite Sequence
    https://codeforces.com/problemset/problem/1462/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n; cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    
    int l = 0, r = n-1;
    while (l < r) {
        cout << a[l] << " " << a[r] << " ";
        l++;
        r--;
    }
    if (n%2==1)
        cout << a[n/2] << " ";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}