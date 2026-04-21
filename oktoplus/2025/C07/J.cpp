/*
    Codeforces 791A - Bear and Big Brother
    https://codeforces.com/problemset/problem/791/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int a, b;
    scanf("%i %i", &a, &b);
    
    int cnt = 0;
    while (a <= b){
        a *= 3;
        b *= 2;
        cnt++;
    }

    printf("%i\n", cnt);

    return 0;
}