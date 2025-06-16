/*
    Mbratona Mineira 2025D - Dados
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k; cin >> k;
    
    int n = 6, cnt = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            for (int c = 1; c <= n; ++c) {
                if (a + b + c == k) {
                    cnt++;
                }
            }
        }
    }

    printf("%.12f\n", cnt / (6.0*6*6));
    
    return 0;
}