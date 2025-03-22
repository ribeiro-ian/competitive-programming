/*
    Codeforces 902A - Visiting a Friend
    https://codeforces.com/contest/902/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool solve(){
    int n, m, a, b, fim;
    scanf("%i %i", &n, &m);
    
    scanf("%i %i", &a, &fim);
    if (a) return false;
    for (int i = 1; i < n; i++) {
        scanf("%i %i", &a, &b);
        
        if (a > fim)
            return false;

        fim = max(fim,b);
    }

    return fim >= m;
}

int main() {
    
    printf("%s\n", solve() ? "YES" : "NO");

    return 0;
}
