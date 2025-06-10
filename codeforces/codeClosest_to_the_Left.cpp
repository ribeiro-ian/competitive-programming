#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, x;
ll v[112345];

ll bs(ll x){
    ll l = 0, r = n-1;
 
    if (x < v[l]) return 0;

    while (l <= r){
        ll m = (l+r)/2;
        
        if (v[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
 
    return l;
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