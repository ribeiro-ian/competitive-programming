/*
    Codeforces 1004A - Sonya and Hotels
    https://codeforces.com/problemset/problem/1004/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, d;
    cin >> n >> d;
    vector <ll> v(n);
    for (auto &i : v) {
        cin >> i;
    }

    ll ans = 2;
    for (int i = 0; i < n-1; ++i) {
        int next = v[i+1],
            curr = v[i];
        
        if (curr + d < next - d) {
            ans += 2;
        }
        else if (curr + d == next - d) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}