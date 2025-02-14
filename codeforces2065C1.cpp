#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int tc, n, m;
int solve(){
    vector <int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    for (int i = 1; i < n-1; i++){
        if (a[i-1] > a[i]){
            if (b[0] - a[i] < a[i-1])
                return 0;
            else
                a[i] = b[0] - a[i]; 
        }
        if (a[i] > a[i+1]){
            if (b[0] - a[i] > a[i+1])
                return 0;
            else
                a[i] = b[0] - a[i]; 
        }
    }

    return 1;
}
    
int main(){
    cin >> tc;
    while (tc--){
        cin >> n >> m;

        printf("%s\n", solve() == 1 ? "YES" : "NO");
    }

    return 0;
}
