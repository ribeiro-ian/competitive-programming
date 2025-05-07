/*
    Beecrowd 1579 - Transporte de Painéis Solares
    https://judge.beecrowd.com/pt/problems/view/1579
*/

#include <bits/stdc++.h>
using namespace std;

int n, c, f, tc;
vector <int> p;

bool isValid(int x) {
    int sum = 0, cnt = 1;
    for (auto v : p) {
        sum += v;
        if (sum > x) {
            cnt++;
            sum = v;
        } 
    }
    return cnt <= c;
}

int bs() {
    int l = *max_element(p.begin(), p.end()),
        r = accumulate(p.begin(), p.end(), 0),
        mid, ans = -1;

    while (l<=r) {
        mid = l+(r-l)/2;

        if (isValid(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tc;
    
    while (tc--) {
        cin >> n >> c >> f;
        p.assign(n, 0);

        for (auto &i : p)
            cin >> i;

        int ans = bs();
        cout << ans << " $" << ans*f*c << "\n";
    }

    return 0;
}