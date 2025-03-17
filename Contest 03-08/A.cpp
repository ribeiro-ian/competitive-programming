/*
    Beecrowd 1318 - Bilhetes Falsos
    https://judge.beecrowd.com/pt/problems/view/1318
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n, m, x;

    while(1){
        scanf("%i %i", &n, &m);

        if (n+m == 0) break;
        
        vector <int> v(n+1,0);
        for (int i = 0; i < m; i++){
            scanf("%i", &x);
            v[x]++;
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (v[i] > 1)
                cnt++;
        }
        
        printf("%i\n", cnt);
    }
        
    return 0;
}
