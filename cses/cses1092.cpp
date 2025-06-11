/*
    CSES 1092 - Two Sets
    https://cses.fi/problemset/task/1092
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
 
    ll total = n*(1+n)/2;
    if (total % 2 == 1){
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    vector <ll> v1, v2;
    
    ll target = total / 2, sum = 0;
    for (int i = n; i >= 1; i--){
        if (sum + i <= target){
            v1.push_back(i);
            sum += i;
        }
        else
            v2.push_back(i);
    }
 
    cout << (int) v1.size() << '\n';
    for (auto &i : v1)
        cout << i << ' ';
    cout << '\n';
    
    cout << (int) v2.size() << '\n';
    for (auto &i : v2)
        cout << i << ' ';
    cout << '\n';

    return 0;
}