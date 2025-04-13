#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc, n, x;
    cin >> tc;

    while (tc--) {
        cin >> n;
        int len = 2*n+1;
        vector <int> p(len);

        set <int> s;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> p[i+j];
                s.insert(p[i+j]);
            }
        }
        
        for (int i = 1; i < len; i++) {
            if (s.find(i) == s.end()) {
                p[1] = i;            
                break;
            }
        }
        
        for (auto &i : p)
            if (i) cout << i << " ";
        cout << "\n";

    }

    return 0;
}