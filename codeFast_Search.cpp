#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, l, r;
ll v[112345];

ll lower(ll x){
    ll l = 0, r = n-1;
 
    while (l <= r){
        ll m = (l+r)/2;
        
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
 
    return l;
}
ll upper(ll x){
    ll l = 0, r = n-1;
 
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
      
    scanf("%lli", &n);
    for (int i = 0; i < n; i++)
        scanf("%lli", &v[i]);
    
    sort(v,v+n);
    // 1 3 4 10 10
    
    scanf("%lli", &k);
    while (k--){
        scanf("%lli %lli", &l, &r);
 
        printf("%lli\n", upper(r) - lower(l));
    }

    return 0;
}