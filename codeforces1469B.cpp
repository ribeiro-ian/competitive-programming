#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, n, m;
    cin >> tc;
    while (tc--){
        cin >> n;
        vector <int> r(n), prefR (n+1, 0);

        for (int i = 0; i < n; i++){
            cin >> r[i];

            prefR[i+1] = prefR[i] + r[i];
        }
        
        cin >> m;
        vector <int> b(m), prefB (m+1,0);

        for (int i = 0; i < m; i++){
            cin >> b[i];

            prefB[i+1] = prefB[i] + b[i];
        }

        cout << *max_element(prefR.begin(), prefR.end())
        + *max_element(prefB.begin(), prefB.end()) << endl;
    }

    return 0;
}
