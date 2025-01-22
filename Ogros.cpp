#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <int> faixas, p, ogros;

int lower_bound(int x){
    int l = 0, r = faixas.size();

    while (l + 1 < r){
        int mid = (l+r)/2;

        if (faixas[mid] > x)
            r = mid;
        else
            l = mid;
    }

    return p[l];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m;
    
    faixas.push_back(1);
    for (int i = 0; i < n-1; i++){
        cin >> x;
        faixas.push_back(x);
    }

    for (int i = 0; i < n; i++){
        cin >> x;
        p.push_back(x);
    }

    for (int i = 0; i < m; i++){
        cin >> x;

        cout << lower_bound(x) <<  " ";
    } cout << endl;


    return 0;
}
