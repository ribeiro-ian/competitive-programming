#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n;

    vector <int> fila (n);
    for (int i = 0; i < n; i++)
        cin >> fila[i];

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        fila.erase(find(fila.begin(),fila.end(), x));
    }
    
    for (auto &&i : fila)
        cout << i << " ";
    cout << endl;

    return 0;
}
