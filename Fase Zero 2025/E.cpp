#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


vector <ll> divisor;
void getDivisores(int N) {
   for (int i = 1; i*i <= N; i++) {
       if (N%i) continue; // i não é divisor de N

       if (N/i == i) divisor.push_back(i); // para não contar sqrt(N) duas vezes
       else {
            divisor.push_back(i);
            divisor.push_back(N/i);
       }
   }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll k;
    ull y, x = 1;
    cin >> y >> k;

    getDivisores(y);

    for (int i = 0; i < divisor.size(); i++){
        ll d = divisor[i];

        if ( (y-d)/d > k) {
            cout << x + d*k << endl;
            return 0;
        }
        x += (y-d);
        k -= (y-d)/d;
    }
    cerr << "k = "  << k << " x: " << x << "\n";
    
    cout << x + y*k << "\n";

    return 0;
}
