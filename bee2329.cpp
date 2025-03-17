/*
    Beecrowd 2329 - Pão a Metro
    https://judge.beecrowd.com/pt/problems/view/2329
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k, x;
int v[112345];

int f(int x){
    int cnt = 0;

    for (int i = 0; i < n; i++){
        cnt += v[i]/x;
    }

    return cnt;
}

int bs(int x){
    int l = 0, r = *max_element(v, v+n), ans = -1, m;

    while (l <= r){
        m = l+(r-l)/2;

        if (f(m) >= k){
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    return ans;
}

int main(){

    scanf("%i %i", &k, &n);

    for (int i = 0; i < n; i++)
        scanf("%i", &v[i]);
    
    printf("%i\n", bs(n));

    return 0;
}
