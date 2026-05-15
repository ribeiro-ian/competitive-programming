/*
    CSES 1713 - Counting Divisors
    https://cses.fi/problemset/task/1713
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, x;
    scanf("%i", &n);

    while(n--){
        scanf("%i", &x);

        int cnt = 0;
        for(int i = 1; i*i <= x; i++){
            if(x % i == 0){
                if(x / i == i) cnt++;
                else cnt += 2;
            }
        }

        printf("%i\n", cnt);
    }

    return 0;
}