/*
    UVA 11369 - Shopaholic
    https://vjudge.net/problem/UVA-11369
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = n-3; i >= 0; i -=3)
        sum += arr[i];
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}