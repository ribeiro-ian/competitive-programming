/*
    Codeforces - Packing Rectangles
    https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll w, h, n;

bool isValid(ll x){
    return (x/h) * (x/w) >= n;
}

ll bs(){
    ll l = 0, r = 1, m, ans = -1;

    while (!isValid(r)) r *= 2;

    while (l <= r){
        m = l+(r-l)/2;

        if (isValid(m)){
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return ans;
}

int main(){

    scanf("%lli %lli %lli", &w, &h, &n);

    printf("%lli\n", bs());

    return 0;
}