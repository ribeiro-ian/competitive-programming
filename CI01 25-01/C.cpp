/*
    Beecrowd 1105 - Sub-prime
    https://judge.beecrowd.com/pt/problems/view/1105
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool cmp(int a){return a>=0;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b, d, c, v;
    
    while (1){
        cin >> b >> n;
        if (b == 0 && n == 0) break;

        vector <int> bancos(b+1);
        for (int i = 1; i <= b; i++)
            cin >> bancos[i];

        for (int i = 0; i < n; i++){
            cin >> d >> c >> v;

            bancos[d] -= v;
            bancos[c] += v;
        }

        printf("%c\n", all_of(bancos.begin()+1, bancos.end(), cmp) ? 'S' : 'N');
    }

    return 0;
}
