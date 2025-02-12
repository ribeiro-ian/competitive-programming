#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    const int MAX = 100+1;
    vector <int> prefix_sum (MAX);
    
    for (int i = 1; i < MAX; i++) // O(MAX)
        prefix_sum[i] = prefix_sum[i-1] + i*i; 
    
    int n;

    // Complexidade O(MAX+k), k = num de entradas
    while(1){
        cin >> n;

        if (!n) break;

        printf("%i\n", prefix_sum[n]);
    }

    return 0;
}