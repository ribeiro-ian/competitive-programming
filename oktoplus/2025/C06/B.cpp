/*
    Beecrowd 1410 - Ele Está Impedido!
    https://judge.beecrowd.com/pt/problems/view/1410
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    while (1){
        int a, d;
        scanf("%i %i", &a, &d);

        if (a+d==0) break;

        int atacantes[a], defensores[d];

        for (int i = 0; i < a; i++)
            scanf("%i", &atacantes[i]);

        for (int i = 0; i < d; i++)
            scanf("%i", &defensores[i]);
        
        sort(defensores, defensores+d);

        printf("%s\n", *min_element(atacantes, atacantes+a) < defensores[1] ? "Y" : "N");
    }

    return 0;
}
