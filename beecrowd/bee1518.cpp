/*
    Beecrowd 1518 - Tartarugas
    https://iudge.beecrowd.com/pt/problems/view/1518
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Editorial: https://crbonilha.com/p/contest-bonilha-editorial/
ll x, y;
struct Turtle {
    ll x, y;
    char dir;
};

// min(dx, dy) é o caminho percorrido na diagonal
// (abs(dx-dy)+1)/2 é o caminho restonte que
// Rafael anda 2 por seg na horizontal ou vertical
ll tempoRafael(ll x, ll y, ll px, ll py) {
    ll dx = abs(px - x), dy = abs(py - y);
    return min(dx, dy) + (abs(dx - dy)+1)/2;
}

ll bs(ll x, ll y, ll tx, ll ty, char dir) {
    ll l = 0, r = 1e18, ans = -1;

    while(l <= r) {
        // mid = tempo
        ll mid = l + (r-l)/2;
        ll px = tx + (dir=='D' ? mid : 0),
           py = ty + (dir=='C' ? mid : 0);
        
        if (tempoRafael(x, y, px, py) <= mid) {
            ans = mid;
            r = mid-1;
        }
        else 
            l = mid+1;
    }
    return ans;
}

void solve() {
    Turtle t[3];

    for (auto& i : t)
        cin >> i.x >> i.y >> i.dir;

    // testa todas possibilidades de ordem
    // permuta a ordem que Rafael pega as tartarugas
    int perm[3] = {0, 1, 2};
    ll ans = LLONG_MAX;
    do {
        ll rx = x, ry = y, tempo = 0;
        
        for (auto i : perm) {
            auto tx = t[i].x, ty = t[i].y;
            auto dir = t[i].dir;

            // tartaruga i andou 'tempo' segundos numa direção
            tx = tx + (dir=='D' ? tempo : 0);
            ty = ty + (dir=='C' ? tempo : 0);
            ll dt = bs(rx, ry, tx, ty, dir);
            tempo += dt;

            // posição de Rafael após capturar a tartaruga i
            // posição incial da tartaruga + dt
            rx = tx + (dir=='D' ? dt : 0);
            ry = ty + (dir=='C' ? dt : 0);
        }

        ans = min(ans, tempo);
    } while (next_permutation(perm, perm+3));

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> x >> y, x && y)
        solve();
    
    return 0;
}