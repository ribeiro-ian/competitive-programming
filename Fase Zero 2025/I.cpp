#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t, l, u;
    cin >> n >> t;

    vector <vector <int>> sensor;
    sensor.assign(n, vector <int> (t));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            cin >> sensor[i][j];
        }
    }

    cin >> l >> u;

    return 0;
}