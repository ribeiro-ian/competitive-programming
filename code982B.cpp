/*
    Codeforces 982B - Bus of Characters
    https://codeforces.com/contest/982/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <int> amount (n,0);
    priority_queue <pii, vector<pii>, greater<pii>> free;
    priority_queue <pii> occupied;

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        free.push({x, i});
    }
   
    string str; // 0 = introvert
    cin >> str; // 1 = extrovert

    vector <int> ans;
    for (auto &c : str) {
        int w, id;
        if (c == '0') {
            tie(w, id) = free.top();
            free.pop();

            occupied.push({w,id});
        }
        else {
            tie(w, id) = occupied.top();
            occupied.pop();
        }
        ans.push_back(id);
    }

    for (auto &i : ans) 
        cout << i << " ";       
    cout << "\n";

    return 0;
}