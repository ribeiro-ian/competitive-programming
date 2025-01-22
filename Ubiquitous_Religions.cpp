#include <bits/stdc++.h>
using namespace std;

const int MAX = 50100;
int religion[MAX];

int root(int x){
    if (religion[x] == x) return x;

    return religion[x] = root(religion[x]);
}

void join(int x, int y){
    religion[root(x)] = root(y);
}

int main(){
    int n, m, x, y, caso = 1;

    while (1){
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++)
            religion[i] = i;
          
        for (int i = 0; i < m; i++){
            cin >> x >> y;
            join(x, y);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (root(i) == i) ans++;

        printf("Case %i: %i\n", caso++, ans);
    }

    return 0;
}
