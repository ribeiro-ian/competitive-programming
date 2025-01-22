#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main(){
    int tc, n, m, k;
    cin >> tc;
 
    while(tc--){
        cin >> n >> m >> k;
 
        vector <int> lists(m), monocarp(k), arr(n);
 
        for (int i = 0; i < m; i++)
            cin >> lists[i];   
 
        for (int i = 0; i < k; i++)
            cin >> monocarp[i];
 
        for (int i = 0; i < n; i++)
            arr[i] = i+1;
        
        if (n == m && m == k){
            for (int i = 0; i < m; i++)
                printf("1");
            printf("\n");
            continue;
        }
        else if (n > m && m > k){
            for (int i = 0; i < m; i++)
                printf("0");
            printf("\n");
            continue;
        }
 
        for (auto &num : lists){
            vector <int> comp_arr = arr;
 
            comp_arr.erase(find(comp_arr.begin(), comp_arr.end(), num));
 
            printf("%i", ((comp_arr == monocarp) ? 1 : 0));
        }
        printf("\n");
    }
 
    return 0;
}