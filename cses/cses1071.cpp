/*
    CSES 1071 - Number Spiral
    https://cses.fi/problemset/task/1071
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
 
    while(tc--){
        ull row, col, ans = 0;
        cin >> row >> col;
        
        if (row >= col){
            if (row % 2 == 0)
                ans = row*row - col + 1;
            else
                ans = (row-1)*(row-1) + col;
        }
        else if (col > row){
            if (col % 2 == 1)
                ans = col * col - row + 1;
            else    
                ans = (col-1)*(col-1) + row; 
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}