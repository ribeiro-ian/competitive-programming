#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    string cpf;

    while(cin >> cpf){
        int d1 = 0, d2 = 0;

        for (int i = 1; i <= cpf.size(); i++){
            int n = cpf[i-1] - '0';

            d1 += n * i;
            d2 += n * (10-i);

            printf("%i", n);
            if (i % 3 == 0 && i != cpf.size())
                printf(".");
        }

        printf("-%i%i\n", (d1 % 11 == 10) ? 0 : d1%11, (d2 % 11 == 10) ? 0 : d2%11);
    }

    return 0;
}
