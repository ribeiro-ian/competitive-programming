/*
    Codeforces 617A - Elephant
    https://codeforces.com/problemset/problem/617/A
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n; scanf("%i", &n);

    printf("%i\n", n / 5 + (n % 5 != 0 ? 1 : 0));

    return 0;
}