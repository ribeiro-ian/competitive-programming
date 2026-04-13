/*
    Codeforces 149A - Business trip
    https://codeforces.com/problemset/problem/149/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n = 12, k;
    cin >> k;

    vector<int> month(n);
    for (int i = 0; i < n; ++i) 
        cin >> month[i];
    sort(month.rbegin(), month.rend());

    int sum = 0, i = 0;
    while (i < n && sum < k) 
        sum += month[i++];
    cout << (sum >= k ? i : -1) << endl;

    return 0;
}