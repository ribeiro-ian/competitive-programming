#include <bits/stdc++.h>
using namespace std;

bool ehVogal(char c){
    string vogais = "aeiou";

    for (auto &v : vogais)
        if (c == v) return true;
    
    return false;
}

int main(){
    string str, nova, nova_invertida;
    cin >> str;

    for (auto &c : str)
        if (ehVogal(c))
            nova += c;

    for (int i = nova.size() - 1; i >= 0; i--) 
        nova_invertida += nova[i]; // string nova invertida

    if (nova == nova_invertida)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}