/*
    Codeforces 208A - Dubstep
    https://codeforces.com/problemset/problem/208/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;

    string word = "";
    for (auto &c : str){
        word += c;

        if (word == "WUB")
            word.clear();
        else if (word.size() > 3 && word.substr(word.size()-3, 3) == "WUB"){
            cout << word.substr(0, word.size()-3) << ' ';
            word.clear();
        }
    }
    if (!word.empty()) cout << word << ' ';
    cout << '\n';

    return 0;
}