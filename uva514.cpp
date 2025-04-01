/*
    UVA 514 - Rails
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, x;

    bool first = true;
    while(scanf("%i", &n), n) {
        if (!first) printf("\n");
        first = false;

        int prev;
        
        while (scanf("%i", &prev), prev) {
            bool flag = true;

            for (int i = 1; i < n; i++) {
                scanf("%i", &x);
                
                if (abs(prev-x) != 1) flag = false;
                prev = x;
            }

            printf("%s\n", flag ? "Yes" : "No");
        }
    }

    return 0;
}