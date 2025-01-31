#include <bits/stdc++.h>
using namespace std;

vector <int> primos;

bool ehPrimo(int n){
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    int tc; cin >> tc;
    
    while(tc--){
        int x; cin >> x;

        printf("%s\n", ehPrimo(x) ? "Prime" : "Not Prime");
    }

    return 0;
}
