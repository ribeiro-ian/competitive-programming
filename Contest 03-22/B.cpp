/*
    Codeforces 4A - Watermelon
    https://codeforces.com/problemset/problem/4/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int w;
    scanf("%i", &w);
    
    printf("%s\n", (w%2==0 && w > 2) ? "YES" : "NO");

    return 0;
}