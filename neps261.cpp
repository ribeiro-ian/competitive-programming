/*
    NEPS 261 - Ogros
    https://neps.academy/br/exercise/261
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k, x;
vector <int> v(112345), p(112345);

int bs(int x){
    int l = 0, r = n-1, m, ans = -1;

    while (l <= r){
        int m = l+(r-l)/2;

        if (v[m] <= x){
            ans = p[m];
            l = m+1;
        }
        else
            r = m-1;
    }

    return ans;
}

int main(){

    cin >> n >> k;
    
    for (int i = 1; i < n; i++)
        cin >> v[i];
    v[0] = 1;
    
    for (int i = 0; i < n; i++)
        cin >> p[i];
        
    while (k--){
        cin >> x;
        cout << bs(x) << " ";
    }
    cout << "\n";
    
    return 0;
}