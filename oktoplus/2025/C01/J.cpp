/*
    Beecrowd 2415 - Consecutivos
    https://judge.beecrowd.com/pt/problems/view/2415
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int maior = 0, cnt = 1;
    int n; cin >> n;

    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n-1; i++){
        if (v[i] == v[i+1])
            cnt++;
        else{
            maior = max(maior, cnt);
            cnt = 1;
        }
    }
    
    maior = max(maior, cnt);
    
    printf("%i\n", maior);    

    return 0;
}
