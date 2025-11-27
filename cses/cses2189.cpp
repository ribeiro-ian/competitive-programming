/*
    CSES 2189 - Point Location Test
    https://cses.fi/problemset/task/2189
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;

    Point () {}
    Point (ll x, ll y) {
        this->x = x;
        this->y = y;
    }

    Point operator-(Point &o)  {
        return Point(x-o.x, y-o.y);
    }
};
ll dot(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
};    

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) {
        Point p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        auto ans = dot(p3 - p1, p3 - p2);
        if (ans > 0)
            cout << "LEFT";
        else if (ans < 0)
            cout << "RIGHT";
        else
            cout << "TOUCH";
        cout << '\n';    
    }

    return 0;
}