#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, x;
ll v[112345];

ll bs(ll x){
    ll l = 0, r = n-1;
 
    if (x  > v[r]) return n+1;

    while (l <= r){
        ll m = (l+r)/2;
        
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
 
    return l+1;
}

int main(){
      
    scanf("%lli %lli", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lli", &v[i]);
 
    while (k--){
        scanf("%lli", &x);
 
        printf("%lli\n", bs(x));
    }

    return 0;
}