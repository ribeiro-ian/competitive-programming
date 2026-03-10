/*
    CSES 1165 - Número Primo
    https://judge.beecrowd.com/pt/problems/view/1165
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        bool flag = true;
        int n; cin >> n;

        for (int i = 2 ; i < n-1; i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
        
        cout << n << (flag ? "" : " nao") << " eh primo\n";
    }

    return 0;
}