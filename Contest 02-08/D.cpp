/*
    Beecrowd 1430 - Composição de Jingles
    https://judge.beecrowd.com/pt/problems/view/1430
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map <char, double> notas{
    {'W',1},
    {'H',1.0/2},
    {'Q',1.0/4},
    {'E',1.0/8},
    {'S',1.0/16},
    {'T',1.0/32},
    {'X',1.0/64}
};

int main(){
    string str;
    while (1){
        cin >> str;
        if (str == "*") break;

        double sum = 0;
        int ans = 0;
        for (auto &c : str){
            if (c == '/'){
                if (sum == 1.0)
                    ans++;

                sum = 0;
            }

            sum += notas[c];
        }

        printf("%i\n", ans);
    }

    return 0;
}