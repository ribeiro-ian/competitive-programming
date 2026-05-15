/*
    Codeforces 2094A - Trippi Troppi
    https://codeforces.com/contest/2094/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        string str, ans = "";
        for(int i = 0; i < 3; i++){
            cin >> str;
            ans += str[0];
        }

        cout << ans << "\n";        
    }

    return 0;
}