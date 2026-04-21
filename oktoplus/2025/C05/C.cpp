/*
    Beecrowd 1808 - O Retorno do Rei
    https://judge.beecrowd.com/pt/problems/view/1808
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    string str;
    cin >> str;

    int total = 0, cnt = 0;
    for (auto c : str)
    {
        if (c == '0')
            total += 9;
        else cnt++;

        total += c - '0';
    }
    
    printf("%.2f\n", (double)total/cnt);

    return 0;
}
