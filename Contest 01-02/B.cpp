#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int cnt;
int fib(int x){
    cnt++;
    if (x == 0) return 0;
    if (x == 1) return 1;


    return fib(x-1) + fib(x-2);
}

int main(){
    int tc; cin >>tc;
    while (tc--)
    {
        int n; cin >> n;

        cnt = 0;
        int ans = fib(n);

        printf("fib(%i) = %i calls = %i\n", n, cnt-1, ans);
    }

    return 0;
}
