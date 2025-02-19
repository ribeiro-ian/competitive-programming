#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    const int MAX = 40+1;

    vector <int> pref(MAX);
    
    pref[0] = 0;
    pref[1] = 1;
    pref[2] = 2;

    for (int i = 3; i < MAX; i++){
        pref[i] = pref[i-1] + pref[i-2];
    }
    
    while(1){
        cin >> n;
        
        if (!n) break;

        printf("%i\n", pref[n]);
    }

    return 0;
}