/*
    CSES 1619 - Restaurant Customers
    https://cses.fi/problemset/task/1619
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <pii> v;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;

        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());

    int cnt = 0, ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        cnt += v[i].second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}