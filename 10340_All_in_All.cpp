#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s, t;

void solve(){
    int i, j;
    i = j = 0;

    while (i < s.size() && j < t.size()){
        if (s[i] == t[j])
            i++;
        j++;
    }

    cout << ((i==s.size()) ? "Yes" : "No") << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while (getline(cin, line)){
        s = line.substr(0, line.find(' '));
        t = line.substr(s.size()+1, line.size()-s.size());

        solve();
    }

    return 0;
}
