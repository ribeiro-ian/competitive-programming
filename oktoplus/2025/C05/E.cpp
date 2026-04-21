/*
    Beecrowd 2062 - OBI URI
    https://judge.beecrowd.com/pt/problems/view/2062
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n;
    string str;
    scanf("%i", &n);

    while (n--){
        cin >> str;
        if ((str.substr(0,2) == "UR" || str.substr(0,2) == "OB") && str.size() == 3)
            printf("%sI", str.substr(0, 2).c_str());
        else
            printf("%s", str.c_str());
        
        if (n) printf(" ");
        else printf("\n");
    }

    return 0;
}
