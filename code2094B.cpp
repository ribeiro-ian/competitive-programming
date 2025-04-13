#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc, n, m, l, r;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> l >> r;

        int start=0, end=0, cnt = 0;
        while (cnt < m){
            if (start > l) {
                start--;
                cnt++;
            }
            if (end < r && cnt < m) {
                end++;
                cnt++;
            }
        }

        cout << start << " " << end << "\n";
    }

    return 0;
}