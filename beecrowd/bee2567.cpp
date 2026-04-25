/*
    Beecrowd 2567 - Virus
    https://judge.beecrowd.com/pt/problems/view/2567
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while (cin >> n) {
        int v[n];
        for (auto&i : v)
            cin >> i;
        sort(v,v+n);

        int sum = 0;
        for (int l = 0, r = n-1; l < r; l++, r--) 
            sum += v[r]-v[l];
        cout << sum << '\n';    
    }

    return 0;
}