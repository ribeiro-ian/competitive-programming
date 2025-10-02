/*
    CSES 1082 - Sum of Divisors
    https://cses.fi/problemset/task/1082
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
constexpr ll MOD = 1e9+7;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    5
    1 = 1
    2 = 1 + 2
    3 = 1 + 3
    4 = 1 + 2 + 4
    5 = 1 + 5
    6 = 1 + 2 + 3 + 6
    7 = 1 + 7
    8 = 1 + 2 + 4 + 8
    9 = 1 + 3 + 9
    10 = 1 + 2 + 5 + 10

    int ans = n;
    for (int i = 2; i*i < n; ++i) {
        int aux = i;
        while (aux <= n) {
            ans = (ans - 1 + n/aux) % mod;
            aux += i;
        }
    }

    n*(n+1)/2;

    return 0;
}