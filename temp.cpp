/*
    Beecrowd Practice A - Binary Search
    https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, x;
ll v[10005];
bool bs(ll x){
    ll l = 0, r = n-1;

    while (l < r){
        ll m = (l+r)/2;

        if (v[m] == x)
            return 1
        else if (v[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }

    return 0;
}

int main(){

    scanf("%lli %lli", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lli", &v[i]);

    while (k--){
        scanf("%lli", &x);

        printf("%s\n", bs(x) ? "YES" : "NO");
    }

    return 0;
}
