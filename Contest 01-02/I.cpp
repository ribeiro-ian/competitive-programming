#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

char alternar(char c){
    if (c == 'X')
        return 'O';
    else
        return 'X';
}

int main(){
    int tc;
    cin >> tc;
    ull c;
    string p;
    int aux;

    while (tc--){
        cin >> p >> c;
        string ans;

        if (c % 2 == 1)
            ans += alternar(p[0]);
        else
            ans += p[0];

        for (int i = 1; i < p.size(); i++){
            c /= 2;
            if (ans[i-1] == 'X')
                ans += alternar(p[i]);

            else if (c % 2 == 1 && c > 0)
                ans += alternar(p[i]);
            
            else
                ans += p[i];
        }
        printf("%s\n", ans.c_str());
    }

    return 0;
}
