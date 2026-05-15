/*
    Codeforces 946A - Partition
    https://codeforces.com/contest/946/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){

    int n, x;
    scanf("%i", &n);

    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%i", &x);

        sum += abs(x);
    }

    printf("%i\n", sum);

    return 0;
}
