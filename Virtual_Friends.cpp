#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
vector <int> social, qtt;
map <string, int> id;
int n, idx;

int root(int x){
    if (social[x] == x) return x;

    return social[x] = root(social[x]);
}

void join(int x, int y){
    x = root(x); y = root(y);

    if (x == y) return;

    social[x] = y;
    qtt[y] += qtt[x];
}

void addPerson(string p){
    if (id.find(p) == id.end()){
        social.push_back(idx);
        qtt.push_back(1);
        id[p] = idx++;
    }
}

int main(){
    int tc; cin >> tc;

    while (tc--){
        idx = 0; id.clear(); social.clear(); qtt.clear();
        string p1, p2;
        
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> p1 >> p2;

            addPerson(p1);
            addPerson(p2);

            if (p1 != p2) join(id[p1], id[p2]);

            printf("%i\n", qtt[root(id[p1])]);
        }
    }

    return 0;
}
