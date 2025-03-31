/*
    Beecrowd 2018 - Olimpíadas de Natal
    https://judge.beecrowd.com/pt/problems/view/2018
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool cmp(pair <string, vector <int>> a, pair <string, vector <int>> b){
    if (a.second[0] != b.second[0])
        return a.second[0] > b.second[0];
    if (a.second[1] != b.second[1])
        return a.second[1] > b.second[1];
    if (a.second[2] != b.second[2])
        return a.second[2] > b.second[2];

    return a.first < b.first;
}

int main(){
    string str;
    map <string, vector <int>> pais;
    
    int cnt = 0, i = 0;
    while (getline(cin, str))
    {
        if (cnt % 4 == 0){
            i = 0;
        }
        else{
            if (pais[str].empty()) pais[str].assign(3, 0);

            pais[str][i]++;
            i++;
        }
            
        cnt++;
    }

    vector <pair <string, vector <int>>> ans;
    for (auto p : pais)
        ans.push_back(p);

    sort(ans.begin(), ans.end(), cmp);

    printf("Quadro de Medalhas\n");
    for (auto p : ans){
        printf("%s ", p.first.c_str());

        for (int i = 0; i < 2; i++){
            printf("%i ", p.second[i]);
        }
        printf("%i\n", p.second[2]);
        
    }

    return 0;
}