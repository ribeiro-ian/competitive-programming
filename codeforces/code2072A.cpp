/*
    Codeforces 2072A - New World, New Me, New Array
    https://codeforces.com/contest/2072/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){

    int tc, n, p, k;
    scanf("%i", &tc);
    
    while(tc--){
        scanf("%i%i%i", &n, &k, &p);
        k = abs(k);

        int ans = (k/p) + (k%p != 0);
        
        printf("%i\n", ans <= n ? ans : -1);
    }

    return 0;
}