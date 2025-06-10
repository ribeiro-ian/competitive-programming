/*
    UVA 10440 - Ferry Loading II
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1381
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, n, t, m, x;

    cin >> tc;
    while (tc--) {
        cin >> n >> t >> m;

        int time = 0, cnt = 0, ans = 0;
        while (m--) {
            cin >> x;
            time = max(time, x);
            cnt++;
            
            cerr << "Time: " << time <<'\n';
            if (cnt >= n){
                time += 2*t;
                cnt = 0;
                ans++;
            }
        }
        cerr << "Time: " << time <<'\n';
        cerr << "cnt: " << cnt <<'\n';
        if (cnt) {
            if (time-t > x){
                time -= t;
            }
            else time = x+t;
            ans++;
        }
        else time -= t;

        cout << time << ' ' << ans << '\n';
        cerr << "================================\n";
    }

    return 0;
}