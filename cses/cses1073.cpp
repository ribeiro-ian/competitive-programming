/*
    CSES 1073 - Towers
    https://cses.fi/problemset/task/1073
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) cin >> i;
    vector <ll> vs = v;
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());
    
    for (auto &i : v) cerr << i << ' ';
    cerr << '\n';
    for (auto &i : vs) cerr << i << ' ';
    cerr << '\n';
 
    return 0;
}