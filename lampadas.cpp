#include <bits/stdc++.h>
using namespace std;

int main(){
    bool a, b;
    a = b = false;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 2)
            b = !b;
        a = !a;
    }
    
    printf("%i\n%i\n", a, b);
}