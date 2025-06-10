/*
    Codeforces 1189B - Number Circle
    https://codeforces.com/contest/1189/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n;
    scanf("%lli", &n);
    ll v[n];
    
    for (int i = 0; i < n; i++) 
        cin >> v[i];
        
    sort(v,v+n);
    
    if (v[n-1] >= v[n-2] + v[n-3]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for (int i = n-1; i >= 0; i-=2) {
            cout << v[i] << " ";
        }
        
        for (int i = n%2; i < n; i+=2) {
            cout << v[i] << " ";
        }
    }
 
    printf("\n");

    return 0;
}