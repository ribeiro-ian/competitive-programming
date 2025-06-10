/*
    CSES 1068 - Weird Algorithm
    https://cses.fi/problemset/task/1068
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ull n; cin >> n;
    while (n > 1) {
        cout << n << ' ';
        
        if (n % 2)
        n = n * 3 + 1;
        else
        n /= 2;
    }
    
    cout << n << '\n';
 
    return 0;
}