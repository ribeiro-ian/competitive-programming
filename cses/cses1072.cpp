/*
    CSES 1072 - Two Knights
    https://cses.fi/problemset/task/1072
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
 
    for (int x = 1; x <= n; x++){
        ull ans = 0, total = x*x;
        
        if (x == 2)
            ans = 6;
        if (x == 3)
            ans = 16;
        if (x >= 3){
            ans += (4 * (total-3))/2;
        }
        
        if (x >= 4){
            ans += (8 * (total-4))/2;
            ans += (((x-4) * 4 + 2 * 2)*(total-5))/2;
        }
        
        if (x >= 5){
            ans += ((x-4) * 4 * (total-7))/2; // centro
            ans += ((x-4) * (x-4) * (total-9))/2; // centro
        }
 
        cout << ans << '\n';
    }

    return 0;
}