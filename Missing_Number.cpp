#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAX = 2*10e5 + 10;
int main(){
    ull n;
    cin >> n;
    ull v[n];
    for (int i = 0; i < n-1; i++)
        cin >> v[i];
    
    sort(v, v+n);
    for (ull i = 0; i < n; i++)
    {
        if (i+1 != v[i]){
            printf("%i\n", i+1);
            break;
        }
    }

    return 0;
}
