#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n; cin >> n;
    while (n > 1){
        printf("%lli ", n);

        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
    }

    printf("%lli\n", n);

    return 0;
}
