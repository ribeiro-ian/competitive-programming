#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, n;
    cin >> tc;

    vector <int> pares, impares;
    while(tc--){
        cin >> n;

        if (n % 2 == 0)
            pares.push_back(n);
        else
            impares.push_back(n);

    }
    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end());
    for (auto &i : pares)
        printf("%i\n", i);
    
    for (int i = impares.size()-1; i >= 0; i--){
        printf("%i\n", impares[i]);
    }

    return 0;
}
