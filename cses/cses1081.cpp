/*
    CSES 1081 - Common Divisors
    https://cses.fi/problemset/task/1081
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
map <int, int> cnt;

int mdc(int a, int b) {
   if (b == 0) return a;
   return mdc(b, a%b);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <ll> v(n);
    for (auto &i : v) {
        cin >> i;
    }
    
    
    cout << ans << '\n';

    return 0;
}