/*
    Beecrowd 2836 - Wifi
    https://judge.beecrowd.com/pt/problems/view/2836
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct {
    int x1,x2,y1,y2;
} pontos;

vector <pontos> ret;

bool cmp(pontos a, pontos b) {
    if (a.x1 != b.x1)
        return a.x1 < b.x1;
    if (a.y1 != b.y1)
        return a.y1 < b.y1;
    if (a.x2 != b.x2)
        return a.x2 < b.x2;
    
    return a.y2 < b.y2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int x1, x2, y1, y2;
    ret.resize(n);
    for (int i = 0; i < n; ++i) {
        
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        ret[i].x1 = min(x1,x2);
        ret[i].x2 = max(x1,x2);

        ret[i].y1 = min(y1,y2);
        ret[i].y2 = max(y1,y2);
    }

    sort(ret.begin(), ret.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        pontos a, b;
        a = ret[i];

        bool flag = true;
        for (int j = i+1; j < n; ++j) {
            b = ret[j];

            if (b.x1 > a.x1 && b.x1 < a.x2 && b.y1 > a.y1 && b.y1 < a.y2) {
                fprintf(stderr, "\no retangulo (%i, %i) (%i, %i) ", b.x1, b.y1, b.x2, b.y2);
                fprintf(stderr, "está dentro do retangulo (%i, %i) (%i, %i)\n", a.x1, a.y1, a.x2, a.y2);
                flag = false;
                break;
            }
        }

        ans += flag;
    }

    cout << ans << "\n";

    return 0;
}