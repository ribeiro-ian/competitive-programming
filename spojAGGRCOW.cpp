/*
    SPOJ - Aggressive cows
    https://www.spoj.com/problems/AGGRCOW/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5;
int tc, n, k, v[MAX];

int f(int x){

    int cnt = 1, prev = v[0];

    for (int i = 1; i < n; i++){ 
        if (v[i] - prev >= x){
            prev = v[i];
            cnt++;
        }
    }
    
    return cnt;
}

int bs(){
    int l = 0, r = v[n-1] - v[0], m, ans = 0;

    while (l<=r){
        m = l + (r-l)/2;

        if (f(m) >= k){
            ans = m;
            l = m+1;
        }
        else
            r = m-1;

    }

    return ans;
}

int main(){

    scanf("%i", &tc);
    while (tc--){
        scanf("%i %i", &n, &k);

        for (int i = 0; i < n; i++)
            scanf("%i", &v[i]);
        sort(v, v+n);
        
        printf("%i\n", bs());
    }

    return 0;
}
