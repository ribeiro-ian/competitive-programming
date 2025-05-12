/*
    Codeforces 645C - Enduring Exodus
    https://codeforces.com/problemset/problem/645/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
vector <int> zeros;
string s;

int bs(int ini, int fim) {
    int l = ini, r = fim, mid;

    while (l <= r) {
        mid = l+(r-l)/2;

        if (zeros[mid]-zeros[ini] < zeros[fim]-zeros[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1 ;
        }
    }
    cerr << "l: " << ini << " r: " << fim << endl;
    cerr << "ans: " <<  max(zeros[mid]-zeros[ini], zeros[fim]-zeros[mid]) << endl;
    
    return min(max(zeros[mid]-zeros[ini], zeros[fim]-zeros[mid]), max(zeros[mid+1]-zeros[ini], zeros[fim]-zeros[mid+1]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    cin >> s;

    for (int i=0; i<n; ++i) {
        if (s[i] == '0') zeros.push_back(i+1);
    }
    
    int l = 0, r = k, m = 0, ans = n;
    while(r < zeros.size()) {
        // Achar a posição do numero 0 no intevalo onde tem-se a menor distancia maxima para os extremos
        // int left = zeros[l], right = zeros[r], mid = zeros[m], next = zeros[m+1];
        // while (max(mid-left, right-mid) > max(next - left, right - next)){
        //     m++;
        //     mid = zeros[m];
        //     next = zeros[m+1];
        // }
        // ans = min(ans, max(mid-left, right-mid));
        ans = min(ans, bs(l,r));
        l++, r++;
    }

    cout << ans << "\n";

    return 0;
}