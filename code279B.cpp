/*
    Codeforces 279B - Books
    https://codeforces.com/problemset/problem/279/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n, t;
    scanf("%lli %lli", &n, &t);

    ll a[n];
    for (int i = 0; i < n; i++) 
        scanf("%lli", &a[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        
        for (int j = i; j < n; j++) {
            sum += a[j];
            
            if (sum <= t) 
                ans = max(ans, j-i+1);
            else
                break;
        }
    }
 
    printf("%i\n", ans);

    return 0;
}