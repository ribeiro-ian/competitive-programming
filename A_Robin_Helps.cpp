#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, n, k, x, robin, ans;

    cin >> tc;
    while (tc--){
        ans = robin = 0;
        
        cin >> n >> k;

        for (int i = 0; i < n; i++){
            cin >> x;

            if (x >= k)
                robin += x;

            else if (x == 0 && robin != 0)
                robin--, ans++;
        }

        printf("%i\n", ans);
    }

    return 0;
}
