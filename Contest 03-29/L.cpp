#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    const int MAX = 1e4+1;
    int n, x;

    scanf("%i", &n);
    
    scanf("%i", &x);
    int best = x, worst = x, cnt = 0;
    for (int i = 1; i < n; i++) {
        scanf("%i", &x);

        if (x > best) {
            best = x;
            cnt++;
        }
        if (x < worst) {
            worst = x;
            cnt++;
        }
    }

    printf("%i\n", cnt);

    return 0;
}