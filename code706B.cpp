/*
    Codeforces 706B - Interesting drink
    https://codeforces.com/problemset/problem/706/B/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, q, v[112345], x;

ll bs(ll x)
{
    ll l = 0, r = n-1, m;

    while (l <= r){
        m = l + (r-l)/2;

        if (v[m] <= x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return l;
}

int main(){

    scanf("%lli", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%lli", &v[i]);
    
    sort(v, v+n);

    scanf("%lli", &q);
    while (q--)
    {
        scanf("%lli", &x);

        printf("%lli\n", bs(x));
    }
    
    return 0;
}
