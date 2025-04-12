/*
    CSES 1641 - Sum of Three Values
    https://cses.fi/problemset/task/1641
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

    pii a[n];
    for (int i = 0; i < n; i++) {
       cin >> a[i].first;
       a[i].second = i + 1;
    }
    sort(a,a+n);

    for (int i = 0; i < n-2; i++) {
        int l = i+1, r = n-1;
 
        while (l < r) {
            int sum = a[i].first + a[l].first + a[r].first;

            if (sum == x) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            else if (sum > x) {
                r--;
            }
            else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}