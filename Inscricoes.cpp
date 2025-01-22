#include <bits/stdc++.h>
using namespace std;

vector <pair <string, int>> v;


void findByName(string ins){
    for (int i = 0; i < v.size(); i++){
        if (v[i].first == ins){
            v[i].second++;
            return;
        }
    }

    v.push_back(make_pair(ins, 1));
}

int main(){
    string nome, ins;
    int n, x;
    while (1){
        v.clear();
        cin >> n;

        if (!n) break;

        for (int i = 0; i < n; i++){
            cin >> nome >> ins;

            findByName(ins);
        }
        
        for (auto &i : v){
            printf("%s %i\n", i.first.c_str(), i.second);
        }
    }

    return 0;
}
