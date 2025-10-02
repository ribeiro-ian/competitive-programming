/*
    Beecrowd 1244 - Ordenação por Tamanho
    https://judge.beecrowd.com/pt/problems/view/1244
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool cmp(string a, string b) {
    return a.length() > b.length();
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    cin.ignore();

    while (tc--) {    
        string frase, palavra;
        vector <string> palavras;
        getline(cin, frase);

        for (int i = 0; i < frase.size(); ++i) {
            if (frase[i] != ' ')
                palavra += frase[i];
            else {
                palavras.push_back(palavra);
                palavra.clear();
            }
        }
        palavras.push_back(palavra);
        stable_sort(palavras.begin(), palavras.end(), cmp);
        
        for (int i = 0; i < palavras.size()-1; ++i)
            cout << palavras[i] << " ";
        cout << palavras.back() << endl;
    }

    return 0;    
}