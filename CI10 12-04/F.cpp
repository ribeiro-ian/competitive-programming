/*
    Codeforce 701C - They Are Everywhere
    https://codeforces.com/problemset/problem/701/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; string str;
    cin >> n;
    cin >> str;
    
    map <char, int> freq;
    for (auto &c : str) 
        freq[c] = 0;
    int unique = freq.size();

    int ans = n;
    for (int l=0, r=0, cnt=0; l < n; l++) {
        while (r < n && cnt < unique) {
            if (freq[str[r]] == 0)
                cnt++;

            freq[str[r]]++;
            r++;
        }

        if (cnt >= unique)
            ans = min(ans, r-l);
            
        freq[str[l]]--;
        if (freq[str[l]] == 0)
            cnt--;
    }

    cout << ans << "\n";

    return 0;
}