/*
    Beecrowd 2088 - Combate à Dengue
    https://judge.beecrowd.com/pt/problems/view/2088
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, x, y;
double ans;
vector <pii> v;

bool ligado(int &n, int j) { return n & (1 << j); }
void ligar(int &n, int j) { n |= (1 << j); }
void desligar(int &n, int j) { n &= ~(1 << j); }

double dist(pii a, pii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

void back(int mask, int idx, double curr) {
    if (mask >= (1 << (n+1))-1) {
        // printf("%.2f\n", curr);
        ans = max(ans, curr);
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (!ligado(mask,i)) {
                double d = dist(v[idx], v[i]);
                
                ligar(mask, i);
                curr += d;
                back(mask, i, curr);
                curr -= d;
                desligar(mask, i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n, n) {
        cin >> x >> y;
        v.resize(n+1);
        v[0] = {x,y};
        for (int i = 1; i <= n; ++i) cin >> v[i].first >> v[i].second;

        ans = 0;
        back(1, 0, 0);
        printf("%.2f\n", ans);
    }

    return 0;
}