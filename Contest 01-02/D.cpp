#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int h1, m1, h2, m2;
    while (1){
        cin >> h1 >> m1 >> h2 >> m2;

        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        int ans = 0;
        
        if (h1 == h2){
            if (m1 > m2)
                ans = 60 * 24;
        }
        
        if (h1 > h2)
            ans = 60 * (24-h1+h2);
        
        if (h1 < h2)
            ans = abs(h1-h2)*60;
        
        if (m2 >= m1)
            ans += abs(m2-m1);
        else
            ans = ans - m1 + m2;

        if (h1 == h2 && m1 == m2)
            ans = 60 * 24;

        printf("%i\n", ans);
    }
    
    return 0;
}
