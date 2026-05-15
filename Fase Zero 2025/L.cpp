#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll m; cin >> m;

    cout << ceil(log2(m*1000000*8)) << endl;


    return 0;
}