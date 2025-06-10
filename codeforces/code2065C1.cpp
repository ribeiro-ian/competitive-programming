#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int tc, n, m;

int solve(){
    cin >> n >> m;
    
    vector <int> a(n+1), b(m+1);

    a[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a.push_back(INT_MAX);

    for (int i = 0; i < m; i++)
    cin >> b[i];
    
    int v = b[0];
    for (int i = 1; i <= n; i++){
        int prev = a[i-1], &cur = a[i], next = a[i+1];

        if (prev < cur && cur < next)
            continue;

        if (cur < prev || cur > next)
            cur = v - cur;
        
        if (cur < prev || cur > next)
            return 0;
    }
    
    return 1;
}

int main(){
    cin >> tc;
    while (tc--){
        printf("%s\n", solve() == 1 ? "YES" : "NO");
    }

    return 0;
}
