/*
    Codeforces 2074C - XOR and Triangle
    https://codeforces.com/contest/2074/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int isValid(int a, int b){
    int c = a ^ b;

    if (a+b > c && a+c > b && b+c>a && c > 0)
        return 0;
    
    return c;
}

int bs(int x){
    for (int i = x-1; i > x/2; i--){
        int res = isValid(x,i);

        printf("%i ^ %i = %i\n", x, i, (x ^ i));

        // if (!res)
        //     return i;
    }

    int l = x/2, r = x-1, m;
    while (l <= r){
        m = l + (r-l)/2;

        if (!isValid(x, m)){
            return m;
        }
    }

    return !isValid(x, l);
}

int main(){

    int tc, x;
    // scanf("%i", &tc);
    
    // while (tc--){
        scanf("%i", &x);

        cout << bs(x) << endl;
    // }

    return 0;
}