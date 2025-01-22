#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int MAX = 1e5+1;
    int tc, n, m, k, x, y;

    cin >> tc;
    while (tc--){
        cin >> n >> m >> k;

        vector <int> v (MAX, 0);
        for (int i = 1; i <= n; i++){
            cin >> x;
            cin >> v[x];
        }

        stack <int> days;
        for (int i = x; i >= 1; i--){
            y = 0;

            for (int j = i; j >= 0; j--){
                if (j >= i - k + 1) y += v[j];
                else break;
            }
            
            days.push(y);
        }

        printf("dias: \n");
        for (stack <int> temp = days; !temp.empty(); temp.pop()){
            printf("%d ", temp.top());
        }
        printf("\n");
        
    }

    return 0;
}
