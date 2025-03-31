/*
    Codeforces 990B - Micro-World
    https://codeforces.com/contest/990/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, k;
    scanf("%i %i", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]); 
    }

    sort(a, a+n, greater<int>());
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1;

        while (a[i] > a[j] && a[i] <= a[j] + k && j < n) {
            cnt++;
            j++;
        }
        i = j-1;
    }
    
    printf("%i\n", n - cnt);

    return 0;
}
