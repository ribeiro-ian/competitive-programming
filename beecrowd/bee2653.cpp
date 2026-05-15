/*
    Beecrowd 2653 - Dijkstra
    https://judge.beecrowd.com/pt/problems/view/2653
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    set <string> s;
    while(cin >> str){
        s.insert(str);
    }
    cout << (int) s.size() << '\n';

    return 0;
}