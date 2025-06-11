/*
    Codeforces 118A - String Task
    https://codeforces.com/problemset/problem/118/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isVowel(char c){
    char vowels[] = {'A', 'O', 'Y', 'E', 'U', 'I'};
    
    for (auto v : vowels){
        if (tolower(v) == tolower(c))
            return true;
    }
    return false;
}

int main() {

    string str, ans="";
    cin >> str;

    for (auto c : str){
        if (!isVowel(c)){
            ans += '.';
            ans += tolower(c);
        }
    }

    cout << ans << endl;

    return 0;
}