#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll v[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i-1]){
            ll aux = abs(v[i] - v[i-1]);
            cnt += aux;
            v[i] += aux;
        }
    }

    printf("%lli\n", cnt);

    return 0;
}
