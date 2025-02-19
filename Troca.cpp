#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n, t, a, b;

    scanf("%i %i", &n, &t);


    vector<int> cima(n+1), baixo(n+1), pref(n+2, 0);
    for (int i = 1; i <= n; i++)
        scanf("%i", &cima[i]);

    for (int i = 1; i <= n; i++)
        scanf("%i", &baixo[i]);
        
    for (int i = 0; i < t; i++){
        scanf("%i %i", &a, &b);

        pref[a]++;
        pref[b+1]--;
    }
    
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + pref[i];

        if (pref[i] % 2 == 0)
            printf("%i ", cima[i]);
        else
            printf("%i ", baixo[i]);
    }
    
    // for (int i = 1; i <= n; i++){
    //     printf("%i ", pref[i]);
    // }
    // printf("\n");
    
    return 0;
}
