#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int f(int n){
    if (n==1) return 1;
    return n*f(n-1);
}

int main(){

    int n;
    while (1){
        cin >> n;
        if (n == 0) break;

        int ans = 1;

        for (int i = 2; i < n; i++)
            ans += f(n)/(f(i)*f(n-i))
    }


    return 0;
}
