#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, n;
    scanf("%i", &tc);

    while (tc--){
        scanf("%i", &n);
        vector <int> v(n);

        for (int i = 0; i < n; i++)
            scanf("%i", &v[i]);
            
            sort(v.begin(), v.end());
            
        for (int i = 0; i < n-1; i++)
            printf("%i ", v[i]);

        printf("%i\n", v[n-1]);
    }

    return 0;
}
