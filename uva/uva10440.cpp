/*
    UVA 10440 - Ferry Loading II
    https://vjudge.net/problem/UVA-10440
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
1
2 10 5
10
40
45
50
51

10 -> volta 30
40 45 -> volta 65
50 51 -> volta 75
*/
void solve(){
    int n, t, m, x;
    cin >> n >> t >> m;

    int a[n], time = 0, cnt = 0, trips = 0;
    for(int i = 0; i < m; ++i) 
        cin >> a[i];

    cout << time << ' ' << trips << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}