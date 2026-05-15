/*
    Beecrowd 1017 - Gasto de Combustível
    https://judge.beecrowd.com/pt/problems/view/1017
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, v;
    cin >> t >> v;

    printf("%.3f\n", t*v/12.0);

    return 0;
}