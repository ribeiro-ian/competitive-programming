#include <bits/stdc++.h>
using namespace std;

vector<int> p;

void runManacher(string str) {
    p.assign(str.size(), 0);
    int l = 0, r = 0;

    for (int i = 1; i < str.size() - 1; ++i) {
        
        // mirror of i around center (l + r)/2
        int mirror = l + r - i;

        // initialize p[i] based on its mirror 
        // if within bounds
        if (i < r)
            p[i] = min(r - i, p[mirror]);

        // expand palindrome centered at i
        while (str[i + 1 + p[i]] == str[i - 1 - p[i]])
            ++p[i];

        // update [l, r] if the palindrome expands 
        // beyond current r
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
}

void manacher(string s) {
    string t = "@";
    for(auto c: s) 
        t += "#" + string(1,c);
    t += "#$";
    
    runManacher(t);
}

int getLongest(int mid, bool isOdd) {
    // map original index to transformed string index
    int pos = 2 * mid + 2 + !isOdd;
    return p[pos];
}

bool check(int l, int r) {
    int len = r-l+1;
    int mid = l + (r-l)/2;
    return len <= getLongest(mid, len % 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;
    
    manacher(str);

    int maxLen = 1;
    int bestStart = 0;  
    for (int i = 0; i < str.size(); i++) {
        
        // check for odd-length palindrome centered at i
        int oddLen = getLongest(i, 1);
        if (oddLen > maxLen) {
            maxLen = oddLen;
            bestStart = i - maxLen / 2;
        }

        // check for even-length palindrome centered 
        // between i and i+1
        int evenLen = getLongest(i, 0);
        if (evenLen > maxLen) {
            maxLen = evenLen;
            bestStart = i - maxLen / 2 + 1;
        }
    }

    cout << str.substr(bestStart, maxLen) << '\n';

    return 0;
}