/*
    Bee 1214 - Acima da Média
    https://judge.beecrowd.com/pt/problems/view/1214
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int tc, n;
    cin >> tc;

    while (tc--){
        cin >> n;
        vector <int> v(n);

        double soma = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            soma += v[i];
        }
        
        double media = soma/n;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] > media)
                cnt++;
        }

        double ans = 100*(double)cnt/(double)n;
        printf("%.3f\%%\n", ans);
    }

    return 0;
}
