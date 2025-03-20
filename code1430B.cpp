/*
    Codeforces 1430B - Barrels
    https://codeforces.com/contest/1430/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int tc, n, k;

    scanf("%i", &tc);
    while (tc--) {
        scanf("%i%i", &n, &k);
        int b[n];

        for (int i = 0; i < n; i++) {
            scanf("%i", &b[i]);
        }
        
        sort(b,b+n);
        int sum = 0;
        while (k--){
            sum += b[n-k-1-1];
        }

        printf("%i\n", abs(sum-b[0]));
    }

    return 0;
}

