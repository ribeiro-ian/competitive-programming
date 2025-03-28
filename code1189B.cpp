/*
    Codeforces 1189B - Number Circle
    https://codeforces.com/contest/1189/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n;
    scanf("%lli", &n);
    ll v[n+2];
    
    for (int i = 1; i <= n; i++) {
        scanf("%lli", &v[i]);
    }
    
    sort(v+1,v+n+1);

    v[0] = v[n];
    v[n+1] = v[1];
    
    for (int i = 1; i <= n; i++) {
        if (v[i] >= v[i-1] + v[i+1]) {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%i ", v[i]);
    }
    printf("\n");

    return 0;
}