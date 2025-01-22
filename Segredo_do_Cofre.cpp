#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> v(n+1, 0), pos(m+1,0), ans(MAX, 0);
    vector <vector <int>> pref(MAX);
    
    for (int i = 0; i < MAX; i++)
        pref[i].resize(n+1, 0);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++){

        for (int j = 0; j < MAX; j++)
            pref[j][i] = pref[j][i-1];

        pref[v[i]][i]++;
    }

    // cerr << "indices:"; for (int i = 0; i <= n; i++) fprintf(stderr, "%2d ", i); cerr << "\nvetor: \t"; for (auto &i : v) fprintf(stderr, "%2d ", i); cerr << "\n";

    // for (int i = 0; i < MAX; i++){ fprintf(stderr, " %i: \t", i); for (auto &&a : pref[i]) if (a) fprintf(stderr, "%2d ", a); else fprintf(stderr, " - "); cerr << "\n";}

    for (int i = 1; i <= m; i++)
        cin >> pos[i];
    
    cerr << "\npos: "; for (auto &i : pos) fprintf(stderr, "%d ", i); cerr << "\n";

    cerr << "indices:  "; for (int i = 0; i < MAX; i++) fprintf(stderr, "%d ", i); cerr << "\n";

    for (int i = 0; i+1 <= m; i++){
        int atual = pos[i], prox = pos[i+1];

        for (int j = 0; j < MAX; j++){
            ans[j] += abs(pref[j][atual] - pref[j][prox]);

            if (atual > prox){
              if (v[atual] == j) ans[j]--;

              if (v[prox] == j) ans[j]++;
            }
        }

        fprintf(stderr, "%2d -> %2d: ", atual, prox); for (auto &i : ans) cerr << i << " "; cerr << endl;
    }

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
