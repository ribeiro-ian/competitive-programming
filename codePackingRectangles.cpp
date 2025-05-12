/*
    Codeforces - Packing Rectangles
    https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll w, h, n;

bool isValid(ll x){
    return (x/h) * (x/w) >= n;
}

ll bs(){
    ll l = 0, r = 1, mid, ans = -1;

    while (!isValid(r)) r *= 2;

    while (l <= r){
        mid = l+(r-l)/2;

        if (isValid(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int main(){

    cin >> w >> h >> n;

    cout << bs() << "\n";

    return 0;
}