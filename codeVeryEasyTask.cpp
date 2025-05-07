/*
    Codeforces - Very Easy Task
    https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll x, y, n;

bool isValid(ll t) {
    if (t < min(x,y)) return false;

    t -= min(x,y); // - time of first copy
    return t/x + t/y >= n-1;
}

ll bs() {
    // bs on time
    ll l = 0, ans = -1, m,
        r = max(x,y)*n;
    
    while (l <= r){
        m = l+(r-l)/2;

        if (isValid(m)) {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return ans;
}

int main(){

    scanf("%lli %lli %lli", &n, &x, &y);

    printf("%lli\n", bs());

    return 0;
}
