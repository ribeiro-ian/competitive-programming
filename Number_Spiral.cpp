#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int tc; cin >> tc;

    int n = sqrt(tc);
    ull cnt = 0;
    while(tc--){
        ull row, col, ans = 0;
        cin >> row >> col;
        
        if (row >= col){
            if (row % 2 == 0)
                ans = row*row - col + 1;
            else
                ans = pow(row-1, 2) + col;
        }
        else if (col > row){
            if (col % 2 == 1)
                ans = col * col - row + 1;
            else
                ans = pow(col-1, 2) + row; 
        }

        printf("%2llu ", ans);
        if (++cnt % n == 0) printf("\n");
    }

    return 0;
}
