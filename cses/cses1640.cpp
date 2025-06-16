/*
    CSES 1640 - Sum of Two Values
    https://cses.fi/problemset/task/1640
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, x;
    cin >> n >> x;

    pii a[n];
    for (int i = 0; i < n; i++) {
       cin >> a[i].first;
       a[i].second = i+1;
    }

    sort(a,a+n);
    int l = 0, r = n -1;
    while (l < r) {
        int sum = a[l].first + a[r].first;
        if (sum == x) {
            cout << a[l].second << ' ' << a[r].second << '\n';
            return 0;
        }
        else if (sum > x) {
            r--;
        }
        else {
            l++;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}