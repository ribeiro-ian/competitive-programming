#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    cin >> n;

    if (n <= 3 && n > 1){
        printf("NO SOLUTION\n");
        return 0;
    }

    for (int i = n-1; i >= 1; i-=2)
    {
        printf("%i ", i);
    }
    for (int i = n; i >= 1; i-=2)
    {
        printf("%i ", i);
    }
    printf("\n");

    return 0;
}
