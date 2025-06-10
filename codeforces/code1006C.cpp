/*
    Codeforces 1006C - Three Parts of the Array
    https://codeforces.com/problemset/problem/1006/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n; cin >> n;
    ll d[n];

    for (auto &e : d)
        cin >> e;
    
    ll l=0, r=n-1, ans=0;
    ll sum1=d[l], sum3=d[r];
    while (l < r) {
        if (sum1 == sum3 && l < r) {
            ans = max(ans, sum1);

            l++;
            sum1+=d[l];
            r--;
            sum3+=d[r];
        }
        else if (sum1 < sum3) {
            l++;
            sum1+=d[l];
        }
        else {
            r--;
            sum3+=d[r];
        }
    }

    cout << ans << "\n";

    return 0;
}