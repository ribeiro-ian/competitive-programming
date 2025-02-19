#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int solve(int x, int y){
    if (x > y)
        swap(x,y);
    
    if (x * 2 == y)
        return 1;
    else if (x % 2 == y % 2 && x % 2 == 1){
        return 1;
    }
    else
        return 0;
}
    
int main(){

    int tc, x, y;
    cin >> tc;

    while (tc--){
        cin >> x >> y;

        printf("%s\n", solve(x,y) ? "YES" : "NO");
    }

    return 0;
}
