/*
    Beecrowd 2654 - Godofor
    https://judge.beecrowd.com/pt/problems/view/2654
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct
{
    string nome;
    int poder, kills, mortes;
} candidato; 

bool cmp(candidato a, candidato b){
    if (a.poder != b.poder)
        return a.poder > b.poder;

    if (a.kills != b.kills)
        return a.kills > b.kills;

    if (a.mortes != b.mortes)
        return a.mortes < b.mortes;

    return a.nome < b.nome;
}

int main(){

    int n; cin >> n;

    vector <candidato> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].nome;   
        // printf("%s\n", v[i].first.c_str());
        cin >> v[i].poder >> v[i].kills >> v[i].mortes;
    }

    sort(v.begin(), v.end(), cmp);

    printf("%s\n", v[0].nome.c_str());

    return 0;
}
