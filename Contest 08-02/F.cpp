#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        vector <int> v(n), v_ord(n);
        
        for (int i = 0; i < n; i++){
            cin >> v[i];
            v_ord[i] = v[i];
        }
        sort(v_ord.begin(), v_ord.end());
        reverse(v_ord.begin(), v_ord.end());

        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] == v_ord[i])
                cnt++;
        }
        printf("%i\n", cnt);
    }

    return 0;
}
