/*
    SPOJ - BSEARCH1
    https://www.spoj.com/problems/BSEARCH1/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int bs(int arr[], int n, int x){
    int l = 0, r = n-1, m, ans = -1;

    while (l <= r){
        m = l + (r-l)/2;

        if (arr[m] == x){
            ans = m;
            r = m-1;
        }
        else if (arr[m] > x)
            r = m-1;
        else
            l = m+1;
    }

    return ans;
}

int main(){

    int n, q, x;
    scanf("%i %i", &n, &q);

    int v[n];

    for (int i = 0; i < n; i++)
        scanf("%i", &v[i]);
    
    while (q--){
        scanf("%i", &x);
        printf("%i\n", bs(v, n, x));
    }

    return 0;
}
