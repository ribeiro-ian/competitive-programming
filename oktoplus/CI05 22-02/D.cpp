/*
    Beecrowd 2018 - Olimpíadas de Natal
    https://judge.beecrowd.com/pt/problems/view/2018
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string, vector <int>> country;

bool comp(country a, country b){
    if (a.second[0] != b.second[0]){
        return a.second[0] > b.second[0];
    }
    if (a.second[1] != b.second[1]){
        return a.second[1] > b.second[1];
    }
    if (a.second[2] != b.second[2]){
        return a.second[2] > b.second[2];
    }

    return a.first < b.first;
}

int main(){

    string str;
    map <string, vector<int>> medals;
    int i = 0, cnt = 0;
    
    while(getline(cin, str)){
        if (cnt % 4 == 0){
            i = 0;
        }
        else{
            if (medals[str].empty()) medals[str].assign(3,0);
            medals[str][i]++;
            i++;
        }

        cnt++;
    }

    vector <country> pairs;
    for (auto m : medals)
        pairs.push_back(m);
    sort(pairs.begin(), pairs.end(), comp);

    printf("Quadro de Medalhas\n");
    for (auto p : pairs)
    {
        printf("%s ", p.first.c_str());

        for (int i = 0; i < 2; i++)
        {
            printf("%i ", p.second[i]);
        }
        printf("%i\n", p.second[2]);
        
    }

    return 0;
}
