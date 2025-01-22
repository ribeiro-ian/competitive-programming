#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, m, a, b, c;
    cin >> tc;

    while (tc--){
        cin >> m >> a >> b >> c;

        int ans = 0;
        if (a < m){
            ans += a;
            ans += min(m-a, c);
            c -= min(m-a, c);
        }
        else
            ans += min(a, m);
        if (b < m){
            ans += b;
            ans += min(m-b, c);
        }
        else
            ans += min(b, m);

        printf("%i\n", ans);
    }

    return 0;
}
