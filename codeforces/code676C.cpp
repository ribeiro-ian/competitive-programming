/*
    Codeforces 676C - Vasya and String
    https://codeforces.com/problemset/problem/676/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
string s;
int change(char c) {
    int cnt = 0, ans = 0;

    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && cnt + (s[r]==c) <= k) {
            cnt += (c == s[r]);
            ans = max(ans, r-l);
            r++;
        }
        cnt -= (c == s[l]);
        ans = max(ans, r-l);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> s;
    cout << max(change('a'), change('b')) << '\n';

    return 0;
}