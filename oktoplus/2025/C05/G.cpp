/*
    Beecrowd 2702 - Escolha Difícil
    https://judge.beecrowd.com/pt/problems/view/2702
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int x, v[3], ans = 0;

    for(int i = 0; i < 3; i++)
    {
        scanf("%i", &v[i]);
    }
    for(int i = 0; i < 3; i++)
    {
        scanf("%i", &x);

        ans += max(0, x-v[i]);
    }
    
    printf("%i\n", ans);

    return 0;
}
