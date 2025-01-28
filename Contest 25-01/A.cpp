#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int achar(vector <int> v, int x){
    for (int i = 0; i < v.size(); i++)
    {
        if (x == v[i]) return i+1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int caso = 1, n, q, x;

    while (1)
    {
        cin >> n >> q;
        if (n == 0 && q == 0)break;
        printf("CASE# %i:\n", caso++);

        vector <int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < q; i++){
            cin >> x;

            int pos = achar(v, x);
            if (pos)
                printf("%i found at %i\n", x, pos);
            else
                printf("%i not found\n", x);
        }
                
    }
    

    return 0;
}
