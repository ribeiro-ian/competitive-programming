#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // um par de elementos consecutivos da seqüência que estejam fora de ordem
    // Marcelo é sempre o primeiro a começar a jogar
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0) break;

        vector <int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        
        int cnt = 0;
        vector <int> sort_v = v;
        sort(sort_v.begin(), sort_v.end());

        

        printf("%s\n", cnt % 2 ? "Marcelo" : "Carlos");
    }
    

    return 0;
}
