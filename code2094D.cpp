#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int two_pointers(int &l, int &r, int n, string str) {
    cerr << str << ":\n";
    cerr << "l: " << l << " r: " << r << '\n';
    while (r < n && str[r] == str[l]) {
        r++;
        
    }
    int ret = r-l;
    l = r;
    cerr << ret << '\n';
    
    return ret;
}

bool solve() {
    string p, s;
    cin >> p >> s;
    cerr << "--------------------------\n";
    int pl = 0, pr = 0, pn = p.size(),
        sl = 0, sr = 0, sn = s.size();

    while (pl < pn) {
        int plen = two_pointers(pl, pr, pn, p),
            slen = two_pointers(sl, sr, sn, s);
        if (slen > 2*plen || plen > slen || p[pl-1] != s[sl-1]) return false;
    }
    if (sl < sn) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << "\n";

    return 0;
}