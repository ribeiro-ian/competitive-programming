#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 500;
int m[MAX][MAX], l, c, a, b, cnt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> l >> c;
    cnt = 0;
    
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> m[i][j];
        }
    }

    int diagX[] = {0, 1, 1, 1, 0, -1, -1, -1},
        diagY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    cin >> a >> b;

    a--, b--;
    //fprintf(stderr, "(%i, %i):\n", a+1,b+1);
    while (cnt < l+c+1) {
        int qtde = 8;

        if ((a == 0 || a == l-1) && (b == 0 || b == c-1)) {
            qtde = 3;
        }
        else if (a == 0 || a == l-1 || b == 0 || b == c-1) {
            qtde = 5;
        }

        int variavel = m[a][b]/qtde;
        m[a][b] = m[a][b]%qtde;

        int maiorzin = INT_MIN;
        int proxLin, proxCol;
        for(int i = 0; i < 8; i++){
            int x = a + -diagX[i];
            int y = b + diagY[i];

            if(x >= 0 && x < l && y >= 0 && y < c){
                m[x][y] += variavel;

                if(m[x][y] > maiorzin){
                    proxLin = x;
                    proxCol = y;
                    maiorzin = m[x][y];
                }
                cerr << x+1 << " " << y+1 << "| = " << m[x][y] << endl;
            } 
        }

        a = proxLin; 
        b = proxCol;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                cerr << m[i][j] << " ";
            }
            cerr << endl;
        }

        fprintf(stderr, "%i: (%i, %i):\n\n", cnt, a+1,b+1);
        cnt++;
    }

    int maiorzao = INT_MIN;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            maiorzao = max(m[i][j], maiorzao);
        }
    }

    cout << maiorzao << endl;
    
    return 0;
}