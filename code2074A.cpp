/*
    Codeforces 2074A - Draw a Square
    https://codeforces.com/contest/2074/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, l, r, d, u;
    scanf("%i", &tc);

    while (tc--){

        scanf("%i%i%i%i", &l, &r, &d, &u);
        
        if (l == r & r == d & d == u)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}