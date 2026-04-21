/*
    CSES 1660 - Subarray Sums I
    https://cses.fi/problemset/task/1660
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n, x;
    scanf("%lli %lli", &n, &x);

    vector <ll> v(n), pref(n+1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lli", &v[i]);
        pref[i+1] = pref[i] + v[i];
    }
    
    map <ll,ll> freq;
    ll cnt = 0;
    for (int i = 0; i <= n; i++) {
        freq[pref[i]]++;
        cnt += freq[pref[i]-x];
    }
    printf("%lli\n", cnt);

    return 0;
}