#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n, time = 0;
    cin >> n;

    vector <int> v(n);
    cin >> v[0];

    for (int i = 1; i < n; i++){
        cin >> v[i];

        if (v[i] - 10 > v[i-1])
            time += 10;
        
        else 
            time += abs(v[i]-v[i-1]);
    }
    
    cout << time + 10 << endl;

    return 0;
}
