#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;

    int a[n], ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];

            if (sum <= t) {
                ans = max(ans, j-i+1);
            } 
            else
                break;
        }
    }
    cout << ans << endl;

    return 0;
}

/*
1 3 3 2 1 1 6 2

*/