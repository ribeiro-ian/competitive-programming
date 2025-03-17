/*
    CSES 1085 - Array Division
    https://cses.fi/problemset/task/1085
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, sum;
ll v[1123456];

ll f(ll m)
{
    ll cnt = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += v[i];

        if (sum > m) {
            sum = v[i];
            cnt += 1;
        }
    }

    return cnt;
}

ll bs(){
    ll l = *max_element(v,v+n), r = sum, ans = 0;
    
    while (l <= r)
    {
        ll m = (l+r)/2;

        if (f(m) <= k){
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return ans;
}


int main(){
    sum = 0;

    scanf("%lli %lli", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%lli", &v[i]);
        sum += v[i];
    }

    printf("%lli\n", bs());   
    
    return 0;
}
