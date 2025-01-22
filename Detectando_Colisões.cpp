#include <bits/stdc++.h>
using namespace std;

int x[2][2];
int y[2][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x[0][0] >> y[0][0] >> x[0][1] >> y[0][1];
    cin >> x[1][0] >> y[1][0] >> x[1][1] >> y[1][1];

    if (x[0][0] > x[1][1] || x[0][1] < x[1][0] || y[0][0] > y[1][1] || y[0][1] < y[1][0])
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}
