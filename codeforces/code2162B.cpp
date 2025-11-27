/*
    Codeforces 2162B - Beautiful String
    https://codeforces.com/contest/2162/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    cerr << '\n';
    int n; cin >> n;
    string s; cin >> s;
    
    cout << count(s.begin(), s.end(), '1') << '\n';
    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            cout << i+1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}