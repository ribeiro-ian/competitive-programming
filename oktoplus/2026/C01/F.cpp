/*
    Beecrowd 1861 - O Hall dos Assassinos
    https://judge.beecrowd.com/pt/problems/view/1861
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<string, int> hall;
    string killer, dead;
    while(cin >> killer >> dead){
        if(hall[killer] >= 0)
            hall[killer]++;
        hall[dead] = -1;
    }

    cout << "HALL OF MURDERERS\n";
    for(auto& [k,c] : hall) 
        if(c >= 0)
            cout << k << ' ' << c << '\n';

    return 0;
}