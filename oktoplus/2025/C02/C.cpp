/*
    Beecrowd 1087 - Dama
    https://judge.beecrowd.com/pt/problems/view/1087
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int x1, y1, x2, y2;

    while (1){
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
        int ans;

        if (x1 == x2 && y1 == y2)
            ans = 0;
        
        else if (abs(x1-x2) == abs(y1-y2) || x1 == x2 || y1 == y2)
            ans = 1;
        else
            ans = 2;
        printf("%i\n", ans);
    }

    return 0;
}