#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    
    while(tc--){
        ull x;
        bool primo = true;
        cin >> x;

        if (x % 2 == 0){
            printf("Not Prime\n");
            continue;
        }

        for (ull i = 2; i < x; i++){
            if (x % i == 0){
                printf("Not Prime\n");
                primo = false;
                break;
            }
        }

        if (primo)
            printf("Prime\n");
    }

    return 0;
}
