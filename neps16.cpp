/*
    OBI 2017 - Primeira Fase - Segredo do Cofre
    https://neps.academy/br/exercise/16
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector <int> v(n+1, 0), pos(m,0), ans(MAX, 0);
    vector <vector <int>> pref(MAX ,vector <int> (n+1,0));
    
    for (int i = 1; i <= n; i++)
        cin >> v[i];
        
    for (int i = 1; i <= n; i++) {
        for (int num = 0; num < MAX; num++)
            pref[num][i] = pref[num][i-1];
        pref[v[i]][i]++;
    }
        
    for (int i = 0; i < m; i++)
        cin >> pos[i];

    ans[v[1]]++;
    for (int i = 0; i < m-1; i++) { // O(M-1)
        int atual = pos[i], prox = pos[i+1];

        for (int num = 0; num < MAX; num++) { 
            ans[num] += abs(pref[num][atual] - pref[num][prox]);

            if (atual > prox) {
                if (v[atual] == num) ans[num]--;

                if (v[prox] == num) ans[num]++;
            }
        }
    }

    for (auto &i : ans)
        cout << i << " "; 
    cout << "\n";
    
    return 0;
}