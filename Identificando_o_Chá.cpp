#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y, x, cnt = 0;

    cin >> x;

    for (int i = 0; i < 5; i++){
        cin >> y;

        if (y == x)cnt++;
    }

    cout << cnt << endl;

    return 0;
}
