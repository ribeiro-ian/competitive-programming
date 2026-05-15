/*
    UVA 10340 - All in All
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string s, t;

    while(cin >> s >> t){
        
        int i = 0;
        for(auto &c : t){
            if(c == s[i]){
                i++;
            }
        }

        printf("%s\n", i == s.size() ? "Yes" : "No");
    }

    return 0;
}