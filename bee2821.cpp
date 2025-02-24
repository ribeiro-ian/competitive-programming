/*
    Bee 2821 - Distribuição de Cartas
    https://judge.beecrowd.com/pt/problems/view/2821
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

map<string,int> value{
    {"A", 1},
    {"J", 11},
    {"Q", 12},
    {"K", 13}
};

int total, n, k;
vector <int> cards;

pii func(int m){
    int cnt = 1, sum = 0, size = 0, biggest = 0;
    for (int i = 0; i < cards.size(); i++, size++)
    {
        sum += cards[i];
        
        if (sum > m){
            biggest = max(biggest, size);
            size = 0;
            sum = cards[i];
            cnt++;
        }
    }

    return {cnt, max(biggest, size)};
}

pii bs(){
    int l = *max_element(cards.begin(), cards.end()),
        r = total;
    pii ans = {0,0};

    while (l <= r){
        int m = (l+r)/2;

        pii ret = func(m);
        if (ret.first <= k){
            ans = make_pair(ret.second, m);
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int main(){
    cin >> n >> k;

    vector <int> cnt(k), sum(k);

    string card;
    total = 0;
    for (int i = 0; i < n; i++){
        cin >> card;

        int v = isalpha(card[0]) ? value[card] : stoi(card);
        cards.push_back(v);

        total += v;
    }

    pii ans = bs();
    printf("%i %i\n", ans.first, ans.second);

    return 0;
}