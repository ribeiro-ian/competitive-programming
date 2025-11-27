#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // Origem e XYZ incrementa todos
    // XY = 0;
    // XZ = 1;
    // YZ = 2;

    int t; cin >> t;
    while (t--) {
        int x, y, z, n, ans = 0;
        int p[3] = {0};

        cin >> n;
        while (n--) {
            cin >> x >> y >> z;
            multiset <int> ms = {x,y,z};
            ms.erase(0);
            
            if (ms.size() == 0 || ms.size() == 3) {
                for (auto &i : p) i++;
            }
            else if (ms.size() == 2) {
                int aux;
                if (!z) aux = 0;
                if (!y) aux = 1;
                if (!x) aux = 2;

                p[aux]++;
            }
            else if (ms.size() == 1) {
                if (x) p[0]++, p[1]++;
                if (y) p[0]++, p[2]++;
                if (z) p[1]++, p[2]++;
            }
        }
        for (auto &i : p) ans = max(ans, i);


        cout << ans << '\n';
    }

    return 0;
}