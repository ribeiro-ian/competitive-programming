/*
    Codeforces 2091B - Team Training
    https://codeforces.com/contest/2091/problem/B
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, n, x, y;

    cin >> tc;
    while (tc--) {
        cin >> n >> x;

        int vec[n];
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec,vec+n, greater<>());

        int cnt = 0, menor = INT_MAX, tam = 0;
        for (int i = 0; i < n; i++) {
            menor = min(menor, vec[i]);
            tam++;

            if (tam * menor >= x) {
                cnt++;
                menor = INT_MAX;
                tam = 0;
            }

            //printf("%i ", vec[i]);
        }
        // printf("\n");
        printf("%i\n", cnt);
    }

    return 0;
}