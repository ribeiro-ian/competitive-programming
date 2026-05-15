/*
    Codeforces 4A - Watermelon
    https://codeforces.com/problemset/problem/4/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int w;
    scanf("%i", &w);
    
    printf("%s\n", (w%2==0 && w > 2) ? "YES" : "NO");

    return 0;
}