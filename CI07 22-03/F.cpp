/*
    Codeforces 1714B - Remove Prefix
    https://codeforces.com/problemset/problem/1714/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {

    int tc, n;
    scanf("%i", &tc);

    while (tc--) {
        scanf("%i", &n);

        vector <int> v(n);

        map <int,bool> check;
        for (int i = 0; i < n; i++){
            scanf("%i", &v[i]);
        }

        int cnt = 0;
        for (int i = n-1; i >= 0; i--){
            if (check[v[i]])
                break;
                
            cnt++;
            check[v[i]] = true;
        }
        
        printf("%i\n", n - cnt);
    }

    return 0;
}