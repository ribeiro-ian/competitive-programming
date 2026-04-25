/*
    Beecrowd 1437 - Esquerda, Volver!
    https://judge.beecrowd.com/pt/problems/view/1437
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char dir[] = {'N', 'L', 'S', 'O'};
int n;

void solve() {
    int i = 0;
    while(n--) {
        char c; cin >> c;

        if (c == 'D')
            i = (i+1) % 4;
        else {
            i--;
            if (i < 0)
                i = 3; 
        }
    }
    cout << dir[i] << '\n';
 }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n, n)
        solve();

    return 0;
}