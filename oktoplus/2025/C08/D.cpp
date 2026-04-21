/*
    Codeforces 327A -  Counting Kangaroos is Fun
    https://codeforces.com/problemset/problem/372/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    const int MAX = 1e5+1;
    int n;
    scanf("%i", &n);

    int s[n], cnt[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%i", &s[i]);
    }

    sort(s,s+n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        printf("%i ", s[i]);


        if (s[i] * 2 > *max_element(s, s+n)) break;
    }
    printf("\n");


    return 0;
}