/*
    UVA 10611 - The Playboy Chimp
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, q, x;
vector <int> h(51234);

int shorter(int x){
    // tallest lady chimp that is shorter than Luchu
    int l=0, r=n-1, m, ans=-1;
    
    while (l <= r){
        int m = l+(r-l)/2;
        
        if (h[m] < x){
            ans = h[m];
            l = m+1;
        }
        else
            r = m-1;
    }

    return ans;
}

int taller(int x){
    // shortest lady chimp that is taller than Luchu
    int l=0, r=n-1, m, ans=-1;
    
    while (l <= r){
        int m = l+(r-l)/2;

        if (h[m] > x){
            ans = h[m];
            r = m-1;
        }
        else
            l = m+1;
    }

    return ans;
}

int main(){
    scanf("%i", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%i", &h[i]);
    
    scanf("%i", &q);

    while(q--){
        scanf("%i", &x);

        int s = shorter(x);
        int t = taller(x);

        s != -1 ? printf("%i ", s) : printf("X ");
        t != -1 ? printf("%i\n", t) : printf("X\n");
    }

    return 0;
}
