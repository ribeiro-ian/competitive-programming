/*
    Codeforces 1152A - Neko Finds Grapes
    https://codeforces.com/contest/1152/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, m, x; 

    scanf("%i%i",&n, &m);

    int odd_chests, even_chests, odd_keys, even_keys;
    odd_chests = even_chests = odd_keys = even_keys = 0;
    for (int i = 0; i < n; i++) {
        scanf("%i", &x);

        if (x % 2)
            odd_chests++;
        else
            even_chests++;
    }

    for (int i = 0; i < m; i++) {
        scanf("%i", &x);

        if (x % 2)
            odd_keys++;
        else
            even_keys++;
    }
    
    printf("%i\n", min(odd_chests, even_keys) + min(even_chests, odd_keys));

    return 0;
}