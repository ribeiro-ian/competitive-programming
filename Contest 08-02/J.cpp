#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map<string,int> valor{
    {"A", 1},
    {"J", 11},
    {"Q", 12},
    {"K", 13}
};

int menorValor(vector <int> v){

    for (int i = 0; i < v.size(); i++){
        if (v[i] == *min_element(v.begin(),v.end()))
            return i;
    }
    

}

int main(){

    int n, m;
    cin >> n >> m;

    queue <int> cartas;
    vector <int> cnt(m), sum(m);

    int total = 0;
    string carta;
    for (int i = 0; i < n; i++){
        cin >> carta;

        int v = isalpha(carta[0]) ? valor[carta] : stoi(carta);
        cartas.push(v);

        total += v;
    }

    int target = total/m;

    int idx=0;
    for (int i = 0; i < n; i++){
        int v = cartas.front();

        if (sum[idx] + v > target && idx < m){
            idx++;
        }
        if (idx >= m) break;

        sum[idx] += v;
        cnt[idx]++;
        cartas.pop();
    }

    while(!cartas.empty()){
        idx = menorValor(sum);

        sum[idx] += cartas.front();
        cnt[idx]++;
        cartas.pop();
    }

    printf("%i %i\n", *max_element(cnt.begin(), cnt.end()), *max_element(sum.begin(), sum.end()));


    return 0;
}
