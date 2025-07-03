/*
    CSES 1625 - Grid Path Description
    https://cses.fi/problemset/task/1625
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int X = 3;
bool mat[X][X];
string str;
vector <tuple<char,int,int>> dir = {{'U', -1, 0}, {'D', 1, 0}, {'L', 0, -1}, {'R', 0, 1}};
int cnt = 0;

void back(int x, int y, int i) {
    if (i == X*X-1 && x == X-1 && y == 0) {
        cerr << ".\n";
        cnt++;
        return;
    }
    if (x == X-1 && y == 0 && i != X*X-1){
        cerr << "+\n";
        return;
    }
    char c = str[i];
    // cerr << "\nc = " << c << '\n';

    for (int k = 0; k < 4; ++k) {
        int lin = x + get<1>(dir[k]);
        int col = y + get<2>(dir[k]);
        char ch = get<0>(dir[k]);
        
        if (!(ch == c || c == '?')) {
            cerr << '\n';
            continue;
        }
        
        if (lin >= 0 && lin < X && !mat[lin][col] && col >= 0 && col < X) {
            cerr << ch;
            mat[lin][col] = true;
            back(lin, col, i+1);
            mat[lin][col] = false;
        }
    }

    cerr << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> str;

    mat[0][0] = true;
    back(0,0,0);

    cout << cnt << '\n';

    return 0;
}