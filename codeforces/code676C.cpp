/*
    Codeforces 676C - Vasya and String
    https://codeforces.com/problemset/problem/676/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
string str;

int solve(char c) {
    int ans = 0;
    for (int l = 0, r = 0, cnt = 0; l < n; l++) {
        while (r < n && cnt <= k) {
            if (str[r] == c) cnt++;
            if (cnt <= k) ans = max(ans, r-l+1);
            r++;
        }
            
        if (str[l] == c) cnt--;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> str;
    cout << max(solve('a'), solve('b')) << "\n";
    cerr << solve('a') << "  " << solve('b') << "\n";

    return 0;
}