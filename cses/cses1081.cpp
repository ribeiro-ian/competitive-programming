/*
    CSES 1081 - Common Divisors
    https://cses.fi/problemset/task/1081
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6+1;
vector <int> num (MAX, 0);

void divisors(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            num[i]++;
            if (i*i != n) {
                num[n/i]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin >> n;

    while(n--) {
        cin >> x;
        divisors(x);
    }

    int ans = 0;
    for (int i = 0; i < MAX; ++i) {
        if (num[i] > 1) {
            ans = max(ans, i);
        }
    }

    cout << ans << endl;

    return 0;
}