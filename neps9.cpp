/*
    OBI 2016 - Segunda Fase  - Jardim de Infância
    https://neps.academy/br/exercise/9
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;

struct Pt {
	int x, y;
	Pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	Pt operator+(const Pt& o) { return Pt(x+o.x, y+o.y); } // soma de vetores
	Pt operator-(const Pt& o) { return Pt(x-o.x, y-o.y); } // subtração de vetores
	void operator+=(const Pt& o) { x += o.x, y += o.y; } // somar vetores com o operador +=
	void operator-=(const Pt& o) { x -= o.x, y -= o.y; } // subtrair vetores com o operador -=
	long long operator*(const Pt& o) { return 1ll*x*o.x + 1ll*y*o.y; } // dot - produto escalar
	long long operator/(const Pt& o) { return 1ll*x*o.y - 1ll*y*o.x; } // cross - produto vetorial
};

ostream& operator<<(ostream& o, const Pt& p) {
    o << p.x << " " << p.y << "\n";
    return o;
}

double dist(Pt a, Pt b) {
    return sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
}

double modulo(Pt a) {
    return sqrt( a.x*a.x + a.y+a.y );
}

bool colinear(Pt a, Pt b, Pt c) { return (b-a) / (c-a) == 0; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n = 7;
    vector <Pt> p (n+1);

    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    Pt t(1, 3);
    if ((p[2] - p[1]) * (p[3]-p[1])== 0 &&
        modulo(p[1]-p[2]) == modulo(p[1]-p[3]) && 
        colinear(p[2], p[3], p[4]) &&
        colinear(p[3], p[4], p[5]) &&
        modulo(p[3]-p[2]) > modulo(p[5]-p[4]) &&
        (p[6]-p[4]) * (p[3]-p[2]) == 0 &&
        (p[7]-p[5]) * (p[3]-p[2]) == 0)
        {
        cerr << "passou\n";
    }
    

    return 0;
}