#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--){
        int n , v[3];

        cin >> n;

        int total = 0;
        for (size_t i = 0; i < 3; i++){
            cin >> v[i];
            total += v[i];
        }
        
        
        int sum = 0, idx = 0;
        while (sum < n % total){
            sum += v[idx];
            idx++;
        }

        printf("%i\n", n / total * 3 + idx);
    }
    

    return 0;
}
