#include <bits/stdc++.h>
using namespace std;

// menor idx = mais tempo
// maior valor = maior habilidade

int value;
bool cmp(int a){return a < value;}

int main(){
    int n;
    cin >> n;;

    vector <int> hab(n);

    for (int i = 0; i < n; i++)
        cin >> hab[i];
    
    int cnt = 0;
    for (int i = 0; i < n; i++){
        value = hab[i];
        cnt += count_if(hab.begin()+i, hab.end(), cmp);
    }
    
    printf("%i\n", cnt);

    return 0;
}