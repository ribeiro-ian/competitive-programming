#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n; scanf("%i", &n);

    printf("%i\n", n / 5 + (n % 5 != 0 ? 1 : 0));

    return 0;
}