/*
    CSES 1047 - Tempo de Jogo com Minutos
    https://judge.beecrowd.com/pt/problems/view/1047
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int hi, mi, hf, mf;
    cin >> hi >> mi >> hf >> mf;

    int ti = hi*60+mi, tf = hf*60+mf, res = 0;

    if(ti == tf){
        res = 24*60;
    }
    else {
        res = tf-ti;

        if(res < 0)
            res += 24*60;
    }

    int hr = res/60, mr = res - hr*60;

    cout << "O JOGO DUROU " << hr << " HORA(S) E " << mr << " MINUTO(S)\n";

    return 0;
}