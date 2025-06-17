/*
    Beecrowd 3053 - Jogo Dos Copos
    https://judge.beecrowd.com/pt/problems/view/3053
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n;
    vector <int> v(3, 0);
    char c; cin >> c;

    v[ c - 'A' ] = 1;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;

        if (x==1) {
            swap(v[0], v[1]);
        }
        if (x==2) {
            swap(v[1], v[2]);
        }
        if (x==3) {
            swap(v[0], v[2]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (v[i] == 1) {
            cout << (char)('A' + i) << '\n';
            break;
        }
    }

    return 0;
}