#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int value;
bool func(int a){return a < value;}

// a mais habilidosa e a que frequenta a academia há mais tempo
// menor i = mais tempo na academia
// hab[i] = nivel de habilidade

int main(){
    ull n, cnt = 0;
    cin >> n;

    vector <int> hab (n);
    for (int i = 0; i < n; i++)
       cin >> hab[i];

    for (int i = 0; i < n-1; i++){
        value = hab[i];
        cnt += count_if(hab.begin()+i+1, hab.end(), func);
    }

    printf("%li\n", cnt);

    return 0;
}