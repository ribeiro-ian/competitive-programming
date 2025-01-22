#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,m,l, cnt;

typedef struct{
    string name;
    int a, b;
    int cost;
} agency;

void readInput(string s, agency &ag){
    int i = s.find(':');
    ag.name = s.substr(0, i++);
    
    string aux = "";
    while (s[i] != ',')
        aux += s[i++];
    i++;

    ag.a = stoi(aux);
    aux.clear();

    while (i < s.size())
        aux += s[i++];
    ag.b = stoi(aux);
}

bool cmp(agency a, agency b){
    
    if (a.cost != b.cost)
        return a.cost < b.cost; 
    
    return a.name < b.name;
}

void calcCost(agency &ag){

    int total = n;
    ag.cost = 0;

    while (total > m){
        if (total / 2 >= m){

            if (total / 2 * ag.a < ag.b){
                ag.cost += total/2* ag.a;
                total -= total/ 2;
            }
            
            else{
                ag.cost += ag.b;
                total /= 2;
            }
        }
        else{
            ag.cost += ag.a;
            total--;
        }
    }
}

void solve(){
    printf("Case %i\n", cnt++);

    cin >> n >> m >> l;

    string s;
    vector <agency> v (l);
    for (int i = 0; i < l; i++){
        cin >> s;
        
        readInput(s, v[i]);
        calcCost(v[i]);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &&ag : v)
        printf("%s %i\n", ag.name.c_str(), ag.cost);
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc; cin >> tc;
    cnt = 1;

    while(tc--){
        solve();
    }

    return 0;
}
