#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll m; cin >> m;

    cout << ceil(log2(m*1000000*8)) << endl;


    return 0;
}