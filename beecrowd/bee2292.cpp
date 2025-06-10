/*
    Bee 2292 - Painel LED
    https://judge.beecrowd.com/pt/problems/view/2292
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

char alternar(char c){
    return c == 'X' ? 'O' : 'X';
}

int main(){

    int tc;
    cin >> tc;
    
    ull c;
    string p;

    while (tc--){
        cin >> p >> c;
        string ans;

        ans += c % 2 == 1 ? alternar(p[0]) : p[0];

        for (int i = 1; i < p.size(); i++){
            if (ans[i-1] == 'X')
                c++; // se o valor anterior trocou para X, vai ocorrer uma troca a mais

            c /= 2; // c = trocas

            ans += c % 2 == 1 ? alternar(p[i]) : p[i];
        }
        
        printf("%s\n", ans.c_str());
    }

    return 0;
}
