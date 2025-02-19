#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    scanf("%i %i", &n, &m);
    
    vector <int> v(n+1, 0), pos(m,0), ans(MAX, 0);
    vector <vector <int>> pref(MAX ,vector <int> (n+1,0));
    
    for (int i = 1; i <= n; i++)
        scanf("%i", &v[i]);
        
    for (int i = 1; i <= n; i++){

        for (int j = 0; j < MAX; j++)
            pref[j][i] = pref[j][i-1];
        
        pref[v[i]][i]++;
    }
        
    for (int i = 0; i < m; i++)
        scanf("%i", &pos[i]);


    ans[v[1]]++;
    for (int i = 0; i < m-1; i++){ // O(M-1)
        int atual = pos[i], prox = pos[i+1];

        for (int j = 0; j < MAX; j++){ // O(10)
            ans[j] += abs(pref[j][atual] - pref[j][prox]);

            if (atual > prox){
                if (v[atual] == j) ans[j]--;

                if (v[prox] == j) ans[j]++;
            }
        }
    }

    for (auto &i : ans)
        printf("%i ", i);
    printf("\n");
    
    return 0;
}
