/*
    Codeforces 2091C - Combination Lock
    https://codeforces.com/contest/2091/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, n;

    cin >> tc;

    while (tc--) {
        cin >> n;
        vector <int> ans;
        set <int> s;
        
        for (int i = 1; i <= n; i++) {
            int v = (i*2 % n) + 1;
            ans.push_back(v);
            s.insert(v);
        }
        
        if (s.size() == n) {
            for (auto &i : ans)
                cout << i << ' ';
            cout << '\n';
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}