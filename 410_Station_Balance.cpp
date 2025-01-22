#include <bits/stdc++.h>
using namespace std;

int c, s, set_cnt;
vector <int> mass;

void solve(){
    int sum = 0;

    mass.clear();
    mass.resize(2*c);
    for (int i = 0; i < s; i++){
        cin >> mass[i];
        sum += mass[i];
    }

    sort(mass.begin(), mass.end());

    for (auto &&i : mass)
        cerr << i << " "; cerr << endl;

    double avg = (double)sum/c, imbalance = 0;

    cout << "Set #" << set_cnt++ << endl;
    for (int i = 0; i < c; i++){
        printf(" %i:", i);
        if (mass[i])
            printf(" %i", mass[i]);
        if (mass[mass.size() - 1 - i])
            printf(" %i", mass[mass.size()-1-i]);
        printf("\n");
        imbalance += abs(avg - (mass[i] + mass[mass.size() - 1 - i]));
    }
    
    printf("IMBALANCE = %.5f\n\n", imbalance);
}   

int main(){

    set_cnt = 1;
    while (cin >> c >> s){
        if (c == EOF) break;
        solve();
    }
    
    return 0;
}
