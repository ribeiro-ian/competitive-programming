#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int carlos = v[0];

    sort(v, v+n);

    if (carlos == v[n-1])
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
