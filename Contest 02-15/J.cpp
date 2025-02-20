/*
    Bee 2235 - Andando no Tempo
    https://judge.beecrowd.com/pt/problems/view/2235
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int v[3], sum = 0;
    set <int> s;

    for (int i = 0; i < 3; i++){
       scanf("%i", &v[i]);
        sum += v[i];
        s.insert(v[i]);
    }

    if (s.size() <= 2){
        printf("S\n");
        return 0;
    }

    int maior = *max_element(v,v+3);
    printf("%s\n", sum - maior == maior ? "S" : "N");

    return 0;
}
