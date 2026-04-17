/*
    Neps 198 - Quadrado Mágico 3x3
    https://neps.academy/br/exercise/198
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    int diagP = 0, diagS = 0, mat[n][n], lin[n] = {0}, col[n] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];

            lin[i] += mat[i][j];
            col[j] += mat[i][j];

            if (i==j)
                diagP += mat[i][j];
            if (i+j==n-1)
                diagS += mat[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (lin[i] != diagP || col[i] != diagP) {
            cout << "NAO\n";
            return 0;
        }
    }
    if (diagS != diagP)
        cout << "NAO\n";
    else
        cout << "SIM\n";

    return 0;
}