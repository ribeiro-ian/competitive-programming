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

    int target = total / m;
    int remainder = total % m;

    for (int i = 0; i < m; i++) {
        while (!cartas.empty() && sum[i] < target + (i < remainder ? 1 : 0)) {
            sum[i] += cartas.front();
            cnt[i]++;
            cartas.pop();
        }
    }

    while (!cartas.empty()) {
        int idx = min_element(sum.begin(), sum.end()) - sum.begin();
        sum[idx] += cartas.front();
        cnt[idx]++;
        cartas.pop();
    }

    printf("%i %i\n", *max_element(cnt.begin(), cnt.end()), *max_element(sum.begin(), sum.end()));

    return 0;
}