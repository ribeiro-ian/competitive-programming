#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, k; 

bool valid(int x) {
    int cnt = n+x-1, idx = k-1;
    if (cnt > m) return false;

    vector <int> a(n, 1);
    a[idx] += x-1;

    int r = idx+1;
    while (r < n) {
        int diff = abs(a[r-1]-a[r]);
        if (diff <= 1) break;

        diff--;
        cnt += diff;
        a[r] += diff;
        r++;
    }

    int l = idx-1;
    while (l >= 0) {
        int diff = abs(a[l+1]-a[l]);
        if (diff <= 1) break;

        diff--;
        cnt += diff;
        a[l] += diff;
        l--;
    }

    return cnt <= n;
}

int bs() {
    int l = 1, r = m, ans = 1, mid;

    while (l <= r) {
        mid = l+(r-l)/2;

        if (valid(m)) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    cout << bs() << "\n";

    return 0;
}