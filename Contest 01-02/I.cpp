#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

char alternar(char c){
    if (c == 'X')
        return 'O';
    else
        return 'X';
}

int main(){

    int tc;
    cin >> tc;
    ull c;
    string p;
    int aux;

    while (tc--){
        cin >> p >> c;

        for (int i = 0, k = 2; i < p.size(); i++, k *= 2){
            if (c % k == 0)
                printf("%c", p[i]);
            else
                printf("%c", alternar(p[i]));
        }
        printf("\n");
    }

    return 0;
}
