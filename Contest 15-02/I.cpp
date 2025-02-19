#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n, m, q, x;
    cin >> n >> m;

    int matriz[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matriz[i][j];

    for (int i = 0; i < q; i++)
    {
        cin >> x;

        for (int i = 0; i < n-x+1; i++){
            for (int j = 0; j < m-x+1; j++){
                prod *= matriz[i][j];
            }
        }
        
    }

    
    

    return 0;
}
