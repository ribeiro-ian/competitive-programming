/*
    CSES 1652 - Forest Queries
    https://cses.fi/problemsetls/task/1652
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, q, col1, col2, lin1, lin2;
    string row;
    scanf("%i %i", &n, &q);

    vector <vector <int>> grid;
    grid.assign(n+1, vector <int> (n+1, 0));


    for (int i = 1, j = 1; i <= n; i++) {
        cin >> row;
        
        for (auto &c : row){
            grid[i][j] = grid[i][j-1];
            
            if (c == '*')
            grid[i][j] = grid[i][j] + 1;
            j++;
        }
        j = 1;
    }

    while (q--) {
        scanf("%i %i %i %i", &lin1, &col1, &lin2, &col2);

        int ans = 0;
        for (int i = lin1; i <= lin2; i++) {
            ans += grid[i][col2] - grid[i][col1-1];
        }

        printf("%i\n", ans);
    }
    

    return 0;
}