/*
    Beecrowd 1168 - LED
    https://judge.beecrowd.com/pt/problems/view/1168
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> num = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solve(){
    string s; cin >> s;
    int cnt = 0;
    for(auto& c : s)
        cnt += num[c-'0'];
    cout << cnt << " leds\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}