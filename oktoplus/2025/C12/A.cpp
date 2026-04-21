/*
    Beecrowd 1040 - Média 3
    https://judge.beecrowd.com/pt/problems/view/1040
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    float n[4], p[] = {2,3,4,1}, div = 0, sum = 0;
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];

        sum += n[i]*p[i];
        div += p[i];
    }

    float media = sum/div;
    printf("Media: %.1f\n", media);
    if (media >= 7) {
        cout << "Aluno aprovado.\n";
    }
    else if (media < 5) {
        cout << "Aluno reprovado.\n";
    }
    else {
        cout << "Aluno em exame.\n";
        float exame; cin >> exame;
        media = (media+exame)/2;
        printf("Nota do exame: %.1f\n", exame);
        
        if (media >= 5) 
            cout << "Aluno aprovado.\n";
        else
            cout << "Aluno reprovado.\n";
        printf("Media final: %.1f\n", media);
    }

    return 0;
}