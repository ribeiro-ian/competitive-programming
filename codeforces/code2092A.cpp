/*
    Coderforces 2092A - Kamilka and the Sheep
    https://codeforces.com/contest/2092/problem/A
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
        int a[n];

        cin >> a[0];
        int greatest, lowest;
        greatest = lowest = a[0];
        
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            
            greatest = max(greatest, a[i]);
            lowest = min(lowest, a[i]);
        }

        cout << greatest - lowest << endl;
    }

    return 0;
}