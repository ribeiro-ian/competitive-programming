/*
    CSES 2104 - Pattern Positions
    https://cses.fi/problemset/task/2104
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int prefix_function(string s, int n){
    vector<int> pi(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;

        if(i > n && pi[i] == n)
            return i-2*n+1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string t, s;
    cin >> t;
    int k; cin >> k;
    while(k--){
        cin >> s;
        cout << prefix_function(s+'#'+t, s.size()) << '\n';
    }

    return 0;
}