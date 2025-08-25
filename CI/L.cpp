#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    
    while (n--) {
        string str; int t;
        cin >> t >> str;

        char tempo = str[0];

        if (tempo == '1') {
            cout << min(t, 45);
            if (t > 45) {
                cout << '+' << t-45;
            }
        }
        else if (tempo == '2') {
            t += 45;
            cout << min(t, 90);
            if (t > 90) {
                cout << '+' << t-90;
            }
        }
        cout << '\n';
    }

    return 0;
}