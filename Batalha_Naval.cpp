#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int n, m, k, num_navio;
char c;

int navios[MAX][MAX];
vector <int> tam_navio (1);

void numerar_navios(int lin, int col){
    if (col < 1 || lin < 1 || lin > n || col > m)
        return;
    
    if (navios[lin][col] != -1)
        return;
    
    navios[lin][col] = num_navio;
    tam_navio[num_navio]++;

    numerar_navios(lin-1, col);
    numerar_navios(lin+1, col);
    numerar_navios(lin, col-1);
    numerar_navios(lin, col+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> c;
            
            if (c == '.')
                navios[i][j] = 0;
            else
                navios[i][j] = -1;
        }
    }

    num_navio = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (navios[i][j] == -1){
                tam_navio.push_back(0);
                numerar_navios(i, j);                
                num_navio++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (navios[i][j] == 0)
                fprintf(stderr, " - ");
            else
                fprintf(stderr, "%2d ", navios[i][j]);
        }
        cerr << endl;
    }

    // cerr << "tam dos navios: ";
    // for (int i = 1; i < tam_navio.size(); i++)
    //     cerr << tam_navio[i] << " "; cerr << "\n";
    
    cin >> k;
    int x, y;
    for (int i = 0; i < k; i++){
        cin >> x >> y;

        tam_navio[navios[x][y]]--;
    }

    // cerr << "tam dos navios: ";
    // for (int i = 1; i < tam_navio.size(); i++)
    //     cerr << tam_navio[i] << " "; cerr << "\n";

    int cnt = 0;
    for (int i = 1; i < tam_navio.size(); i++)
        if (tam_navio[i] == 0) cnt++;
    
    cout << cnt << endl;

    return 0;
}
