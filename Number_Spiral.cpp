#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
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

        printf("%llu\n", ans);
    }

    return 0;
}
