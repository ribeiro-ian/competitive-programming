#include <bits/stdc++.h>
using namespace std;

map <string, string> w;

string shorter(string s){
    return ( (s.size() <= w[s].size()) ? s : w[s] );
}

int main(){
    int n, m;
    string x, y;

    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        w[x] = y;
    }
    
    for (int i = 0; i < n; i++){
        cin >> x;
        cout << shorter(x) << " ";
    }
    cout << endl;

    return 0;
}
