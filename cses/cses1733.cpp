/*
    CSES 1733 - Finding Periods
    https://cses.fi/problemset/task/1733
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));

        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    auto zarr = z(s);
    int n = zarr.size();
    for (int i = n-1; i >= 0; --i) {
        if (zarr[i] + i == n) 
            cout << zarr[i] << ' ';
    }
    cout << '\n';

    return 0;
}