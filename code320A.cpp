/*
    Codeforces 230A - Magic Numbers
    https://codeforces.com/contest/320/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool solve(string str) {

    string aux = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] = '1' || str[i] != '4')
            return false;

        aux += str[i];

        if (aux == "144") aux.clear();
        
    }
}

int main() {
    string str;
    cin >> str;



    printf("%s\n", solve(str) ? "YES" : "NO");

    return 0;
}
