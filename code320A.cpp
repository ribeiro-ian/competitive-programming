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
        if (str[i] != '1' && str[i] != '4')
            return false;

        aux += str[i];

        cerr << aux << endl;
        if (str[i] == '1') aux = "1";
        else if (aux == "4") return false;
        else if (aux == "14") continue;
        else if (aux == "144") aux.clear();
        else return false;
    }
    return true;
}

int main() {
    string str;

    cin >> str;

    printf("%s\n", solve(str) ? "YES" : "NO");

    return 0;
}
