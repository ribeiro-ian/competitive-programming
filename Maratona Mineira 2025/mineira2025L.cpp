/*
    Mbratona Mineira 2025L - Lucro
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/L
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a,b,c;
    cin >> a >> b >> c;

    if(a * b == c){
        cout << "S\n";
    }
    else
        cout << "N\n";

    return 0;
}