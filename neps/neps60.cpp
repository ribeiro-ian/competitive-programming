/*
    Neps 60 - Sanduíche
    https://neps.academy/br/exercise/60
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d;

    cin >> n >> d;

    int v[2*n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[n+i] = v[i];
    }

    int cnt = 0;
    for (int l = 0, r = 0, sum = 0; l < n; l++) {
        while (r-l+1 <= n && sum + v[r] <= d) {
            sum += v[r];
            r++;
        }

        if (sum == d) cnt++;
        sum -= v[l];
    }

    cout << cnt << '\n';

    return 0;
}