/*
    Codeforces 1036A - Function Height
    https://codeforces.com/problemset/problem/1036/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll ans = ceil((long double)k/n);
    cout << ans << '\n';
    cerr << k/n << endl;

    return 0;
}