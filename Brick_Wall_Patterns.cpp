#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n, w[51];

    w[0] = w[1] = 1;
    for (int i = 2; i < 51; i++)
        w[i] = w[i-1] + w[i-2];

    while (n != 0){
        cin >> n;

        if (n==0) break;

        printf("%llu\n", w[n]);
    }
    
    return 0;
}
