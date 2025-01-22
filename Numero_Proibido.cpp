#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int n, x;
    set <unsigned int> s;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }

    while(cin >> x){
        if (s.find(x) != s.end())
            cout << "sim\n";
        else
            cout << "nao\n";
    }
    
    return 0;
}
