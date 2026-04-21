/*
    Beecrowd 1557 - Matriz Quadrada III
    https://judge.beecrowd.com/pt/problems/view/1557
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ws(int n) {
    return 1 + (int) log10(n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while (cin >> n, n) {
        int s = ws(1 << (n+n-2));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << setw(s) << (1 << (i+j));
                if (j == n-1) cout << '\n';
                else cout << ' ';       
            }
        }
        cout << '\n';
    }

    return 0;
}