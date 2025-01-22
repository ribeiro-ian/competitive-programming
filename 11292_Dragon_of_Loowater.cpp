#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j, sum;
    while (1){
        cin >> n >> m;
        
        if (n == 0 && m == 0) break;

        vector <int> heads(n), heights(m);

        for (i = 0; i < n; i++)
            cin >> heads[i];
        
        for (i = 0; i < m; i++)
            cin >> heights[i];
        
        sort(heads.begin(), heads.end());
        sort(heights.begin(), heights.end());

        sum = i = j = 0;
        while (i < heads.size() && j < heights.size()){
            if (heights[j] >= heads[i])
                sum += heights[j], i++;
            
            j++;
        }

        if (i != n)
            printf("Loowater is doomed!\n");
        else
            printf("%i\n", sum);
    }
    



    return 0;
}
