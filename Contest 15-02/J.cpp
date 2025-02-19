#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int v[3];
    set <int> s;

    for (int i = 0; i < 3; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    if (s.size() <= 2){
        printf("S\n");
        return 0;
    }

    int maior = *max_element(v,v+3);
    int soma = 0;
    for (int i = 0; i < 3; i++){
        if (v[i] != maior)
            soma += v[i];
        else
            soma-= v[i];
    }

    if (soma == 0)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
