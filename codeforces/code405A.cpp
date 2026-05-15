/*
    Codeforces 405A - Gravity Flip
    https://codeforces.com/problemset/problem/405/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n; scanf("%i", &n);
    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%i", &a[i]);
    
    sort(a,a+n);
    for(int i = 0; i < n; i++)
        printf("%i ", a[i]);

    return 0;
}