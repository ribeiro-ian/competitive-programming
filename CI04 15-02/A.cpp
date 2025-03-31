/*
    Bee 1089 - Loop Musical
    https://judge.beecrowd.com/pt/problems/view/1089
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    while (1)
    {
        cin >> n;
        if (!n) break;

        vector <int> v(n+1);
        
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        v[0] = v[n];
        v.push_back(v[1]);
                
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            int prev = v[i-1], next = v[i+1], curr = v[i];

            if (curr < min(prev, next) || curr > max(prev, next))
                cnt++;
        }
        
        printf("%i\n", cnt);
    }

    return 0;
}
