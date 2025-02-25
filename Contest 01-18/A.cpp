/*
    Beecrowd 1162 - Organizador de Vagões
    https://judge.beecrowd.com/pt/problems/view/1162
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int tc, n;
    cin >> tc;

    while (tc--){
        cin >> n;
        vector <int> v(n);

        for (int i = 0; i < n; i++) 
            cin >> v[i];
        
        vector <int> v_ord = v;
        sort(v_ord.begin(), v_ord.end());

        int cnt = 0;
        while (v_ord != v){
            for (int i = 0; i < n - 1; i++){
                if (v[i] > v[i+1]){
                    swap(v[i], v[i+1]);
                    cnt++;
                }
            }
        }

        printf("Optimal train swapping takes %i swaps.\n", cnt);
    }

    return 0;
}
