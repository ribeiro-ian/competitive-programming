#include <bits/stdc++.h>
using namespace std;

int main(){
    int monica, filhos[3];
    cin >> monica;

    cin >> filhos[0] >> filhos[1];
    
    filhos[2] = monica - filhos[0] - filhos[1];

    cout << *max_element(filhos, filhos+3) << endl;
    // sort(filhos, filhos+3);
    // cout << filhos[2] << endl;
    
    return 0;
}