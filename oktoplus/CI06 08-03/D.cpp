/*
    Beecrowd 1743 - Máquina de Verificação Automatizada
    https://judge.beecrowd.com/pt/problems/view/1743
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int x[5], y[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%i", &x[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        scanf("%i", &y[i]);
    }

    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (x[i] == y[i])
        {
            flag = false;
            break;
        }
    }
    
    printf("%s\n", flag ? "Y" : "N");

    return 0;
}
