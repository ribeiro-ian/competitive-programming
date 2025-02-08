#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    while(1){
        cin >> n;

        if (n == 0) break;

        ull ans = 1;

        for (int i = 1; i < n; i++)
            ans += (n-i+1) * (n-i+1);
        
        printf("%llu\n", ans);
    }

    return 0;
}
