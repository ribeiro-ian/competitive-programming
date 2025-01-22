#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, n;
    cin >> tc;

    while (tc--){
        cin >> n;
        
        vector <int> a(n),b(n);

        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        
        for (size_t i = 0; i < n; i++)
            cin >> b[i];

        int ans = 0;
        for (int i = 0; i < n-1; i++){
            if (a[i] > b[i+1]){
                ans += abs(a[i] - b[i+1]);
            }
        }
        ans += a[n-1];

        printf("%i\n", ans);
    }

    return 0;
}
