/*
    Maratona Mineira 2025C - Cartas
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int J = 4, C = 3;

int jog[J][C];
map <string, int> pontos;

void definirPontos() {
    vector <string> v = {"4P","7C","AE","7O","3","2","A","K","J","Q","7","6","5","4"};
    reverse(v.begin(), v.end());
    for (int i=0;i<v.size();++i) {
        pontos[v[i]] = i+1;
    }
}

void printCartas() {
    for (int i = 0; i < J; ++i) {
        fprintf(stderr, "%c: ", 'A'+i);
        for (int j = 0; j < C; ++j)
            cerr << jog[i][j] << ' ';
        cerr << '\n';
    }
    cerr << '\n';
}

void rodada(int idx) {
    int maior, maior1 = 0, maior2 = 0, maiorIdx = 0;
    maior = maior1 = jog[0][C-idx];
    jog[0][C-idx] = 0;
    
    for (int j = 1; j < J; ++j) {
        int idx = -1;
        int *arr = jog[j];

        // Jogada
        for (int i = 0; i < C; ++i) {
            if (!arr[i]) continue;
            
            // pegar o menor por padrão = primeiro valor != 0
            if (idx == -1 && arr[i] < maior) {
                idx = i;
            }
            // time diferente do maior = pegar maior que o "maior"
            if (maiorIdx % 2 != j % 2) {
                if (arr[i] > maior) {
                    idx = i;

                    if (j%2 == 0) maior1 = max(maior1, arr[i]);
                    else maior2 = max(maior2, arr[i]);
                }
            }
        }
        
        if (idx == -1) {
            for (int i = 0; i < C; ++i) {
                if (arr[i]) {
                    idx = i;
                    
                    if (j%2 == 0) maior1 = max(maior1, arr[i]);
                    else maior2 = max(maior2, arr[i]);
                    break;
                }
            }
        }

        if (arr[idx] > maior) {
            maior = arr[idx];
            maiorIdx = j;
        }

        arr[idx] = 0;
    }

    if (maior1 == maior2) {
        cout << "0 ";
    }
    else if (maiorIdx % 2 == 0) {
        cout << "1 ";
    }
    else {
        cout << "2 ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    definirPontos();

    for (int i = 0; i < J; ++i) {
        string s;
        for (int j = 0; j < C; ++j) {
            cin >> s;

            if (s != "4P" && s!= "7C" && s != "AE" && s != "7O") {
                string aux; aux += s[0];
                jog[i][j] = pontos[aux];
            }
            else {
                jog[i][j] = pontos[s];
            }

        }
        sort(jog[i], jog[i]+C);
    }

    for (int i = 0; i < 3; ++i) {
        rodada(i+1);
    }
    cout << "\n";

    return 0;
}