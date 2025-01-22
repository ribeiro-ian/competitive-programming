#include <bits/stdc++.h>
using namespace std;

const int MAX = 10e5+10;
int bit[MAX], v[MAX];
int n, q, x, k, p;

int lsb(int x){
    return x & -x;
}

int sum(int i){
    int ans = 0;
    for(;i > 0; i -= lsb(i))
        ans += bit[i];
    return ans;
}

void upd(int i, int v){
    for (; i <= n; i += lsb(i))
        bit[i] += v;
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        upd(i, v[i]);
    }

    for (int i = 0; i < q; i++){
        
        cin >> x >> k;
        if (x == 0){
            cin >> p;
            upd(k, p-v[k]);
            v[k] = p;
        }
        else
            printf("%i\n", sum(k));
    }

    return 0;
}
