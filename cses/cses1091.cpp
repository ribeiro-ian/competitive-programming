/*
    CSES 1091 - Concert Tickets
    https://cses.fi/problemset/task/1091
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, t;
vector <ll> v(212345);
vector <bool> visited(212345);

ll bs(ll x){
    ll l = 0, r = n-1, m;

    if (x < v[l]) return -1;

    while (l<=r){
        m = (l+r)/2;

        if (v[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }

    return l-1;
}

int main(){

    scanf("%lli %lli", &n, &k);
    
    for (int i = 0; i < n; i++)
        scanf("%lli", &v[i]);
        
    while (k--){
        sort(v.begin(), v.end());
        scanf("%lli", &t);

        ll ans = bs(t);
        printf("%lli\n", v[ans]);
        v[ans] = INT_MAX;
    }

    return 0;
}
