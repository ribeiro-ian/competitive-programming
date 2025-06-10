/*
    UVA 514 - Rails
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;

    while(cin >> n, n) {
        
        while (1) {
            stack <int> in;
            queue <int> out;

            for (int i = 1; i <= n; i++) {
                cin >> x;
                if (!x) break;
                
                out.push(x);                
                in.push(i);

                while (!in.empty() && in.top() == out.front()) {
                    in.pop(), out.pop();
                }

            }
            
            if (!x) break;
            
            
            cout << (in.empty() ? "Yes" : "No") << '\n';
        }
        cout << '\n';
    }

    return 0;
}