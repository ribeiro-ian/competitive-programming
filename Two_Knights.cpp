#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n;
    cin >> n;

    for (int x = 1; x <= n; x++){
        
        ull ans = (x*x * (x*x-1))/ 2; // total
        ans -= 4 * (x - 1) * (x - 2); //attacking


        printf("%llu\n", ans);
    }

    return 0;
}
