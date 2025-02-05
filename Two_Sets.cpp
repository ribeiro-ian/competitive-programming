#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull n;
    cin >> n;

    ull total = n*(1+n)/2;
    if (total % 2 == 1){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    vector <ull> v1, v2;
    ull sum = 0;
    
    ull target = total / 2;
    for (int i = n; i >= 1; i--){
        if (sum + i <= target){
            v1.push_back(i);
            sum += i;
        }
        else
            v2.push_back(i);
    }

    printf("%i\n", v1.size());
    for (auto &i : v1)
        printf("%llu ", i);
    
    printf("\n%i\n", v2.size());
    for (auto &i : v2)
        printf("%llu ", i);
    printf("\n");

    return 0;
}
