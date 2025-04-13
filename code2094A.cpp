#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string str, ans = "";
        for (int i = 0; i < 3; i++) {
            cin >> str;
            ans += str[0];
        }

        cout << ans << "\n";        
    }

    return 0;
}