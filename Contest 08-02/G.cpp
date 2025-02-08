#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n, m, x;
    cin >> n >> m;

    int tempo[n], ans = 0;
    priority_queue <int, vector<int>, greater <int>> fila;

    for (int i = 0; i < n; i++){
        cin >> x;
        fila.push(tempo[i]);
    }

    for (int i = 0; i < m; i++){
        cin >> x;

        if (!fila.empty()){
            ans += fila.top() * x;
            fila.pop();

            
        }
    }
    

    return 0;
}
