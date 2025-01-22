#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    string a;
    while (tc--){
        cin >> a;

        for (int i = a.size()- 1; i >= 0; i--){
            if (a[i] == 'p')
                printf("q");
            else if(a[i] == 'q')
                printf("p");
            else
                printf("w");
        }
        printf("\n");
    }
    
    return 0;
}
