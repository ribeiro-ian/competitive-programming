/*
    Beecrowd 2815 - Digitador Gago
    https://judge.beecrowd.com/pt/problems/view/2815
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    string str;
    vector <string> palavras;

    while (cin >> str){
        palavras.push_back(str);
    }

    for (int i=0; i < palavras.size(); i++){
        string p = palavras[i];

        if (p.size() < 4)
            printf("%s", p.c_str());
        else if (p.substr(0, 2) == p.substr(2,2))
            printf("%s", p.substr(2).c_str());
        else
            printf("%s", p.c_str());

        if (i != palavras.size()-1) printf(" ");
        else printf("\n");
    }

    return 0;
}
