/*
    Beecrowd 2653 - Dijkstra
    https://judge.beecrowd.com/pt/problems/view/2653
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){

    set <string> s;
    string str;
    while(cin >> str)
    {
        s.insert(str);
    }

    cout << s.size() << endl;

    return 0;
}