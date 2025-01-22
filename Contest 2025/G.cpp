#include <bits/stdc++.h>
using namespace std;

int main(){
    int tam_praia, n, tc = 1;

    while(1){
        cin >> tam_praia >> n;

        if (tam_praia == 0 && n == 0) break;

        printf("Teste %i\n", tc++);

        vector <pair <int, int>> s (n);
        for (int i = 0; i < n; i++)
            cin >> s[i].first >> s[i].second;

        sort(s.begin(), s.end());

        int ini = s[0].first,
            fim = s[0].second;

        for (int i = 0; i < n; i++){
            if (s[i].first > fim){
                printf("%i %i\n", ini, fim);
                ini = s[i].first;
                fim = s[i].second;
            }
            else if (s[i].second > fim){
                fim = s[i].second;
            }
        }
        printf("%i %i\n\n", ini, fim);
    }

    return 0;
}
