#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    ll sum = 0;
    for(auto &c : str){
        int v = c - 'a';

        sum += ('z' - v) - 'a' + 1;
    }

    cout << sum << '\n';

    return 0;
}