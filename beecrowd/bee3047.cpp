/*
    Beecrowd 3047 - A idade de Dona Mônica
    https://judge.beecrowd.com/pt/problems/view/3047
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int monica, filhos[3];
    cin >> monica >> filhos[0] >> filhos[1];

    filhos[2] = monica - filhos[0] - filhos[1];
    sort(filhos, filhos+3);

    cout << filhos[2] << '\n';

    return 0;
}