/*
    CSES 2190 - Line Segment Intersection
    https://cses.fi/problemset/task/2190
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Point {
    ll x, y;

    Point () {}
    Point (ll x, ll y) {
        this->x = x;
        this->y = y;
    }

    Point operator-(Point& o)  {
        return Point(x-o.x, y-o.y);
    }

    bool operator==(Point& o) {
        return (x == o.x && y == o.y);
    }

    void read() {
        cin >> x >> y;
    }
};

ll dot(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    Point a, b;

    int getSide(Point &p) {
        auto ans = dot(p - a, p - b);
        if (ans > 0)
            return 1;
        else if (ans < 0)
            return -1;
        else
            return 0;
    }

    // Calculate slope = inclinação
    double getSlope() {
        if (a.x == b.x)  // Vertical line
            return INF;
        
        return 1.*(b.y - a.y) / (b.x - a.x);
    }

    double getYIntercept() {
        if (a.x == b.x)  // Vertical line
            return a.x; // For vertical lines, the 'y-intercept' is the x-value
        return a.y - getSlope() * a.x;
    }

};

Point a, b, c, d;

bool areCollinear(Line& l1, Line& l2) {
    if (l1.getSlope() == l2.getSlope()) {
        if (l1.getSlope() == INF) 
            return l1.a.x == l2.a.x; // Check if they share the same x-coordinate
        
        return l1.getYIntercept() == l2.getYIntercept();
    }
    return false;
}


bool hasIntersection() {
    // one vertex intersect
    if (a==c || a == d || b == c || b == d)
        return true;
    
    Line l1 = {a,b},
         l2 = {c,d};
    
    if (areCollinear(l1, l2))
        return true;

    // one point intersect
    if (l1.getSide(c) == -l1.getSide(d) && l2.getSide(a) == -l2.getSide(b))
        return true;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while (t--) {
        a.read(); b.read(); c.read(); d.read();

        if (hasIntersection())
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }

    return 0;
}