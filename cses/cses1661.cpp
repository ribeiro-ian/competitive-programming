/*
    CSES 1661 - Subarray Sums II
    https://cses.fi/problemset/task/1660
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    ll k, cnt = 0;
    
    cin >> n >> k;

    vector <ll> v(n), pref(n+1);
    map <ll, ll> pref_cnt;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i+1] = pref[i] + v[i];
    }
    
    for (int i = 1; i <= n; i++) { // O(n)
        cnt += (pref_cnt[pref[i] - k]);
        pref_cnt[pref[i]] += 1;
    } 
    
    printf("%lli\n", cnt);

    return 0;
}
