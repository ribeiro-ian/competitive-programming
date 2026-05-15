/*
    Codeforces 282A - Bit++
    https://codeforces.com/problemset/problem/282/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){

    int n; string str;
    scanf("%i", &n);

    int ans = 0;
    while(n--){
        cin >> str;

        if(str[1]=='+')
            ans++;
        else
            ans--;
    }
    printf("%i\n", ans);

    return 0;
}