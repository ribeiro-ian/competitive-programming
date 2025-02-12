#include <bits/stdc++.h>
using namespace std;

int main(){
    int tempos[3], temposOrdenado[3];

    for (int i = 0; i < 3; i++){
        cin >> tempos[i];
        temposOrdenado[i] = tempos[i];
    }
    
    sort(temposOrdenado, temposOrdenado+3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            if (tempos[j] == temposOrdenado[i]){
                cout << j+1 << endl;
                break;
            }
    }
    
    return 0;
}