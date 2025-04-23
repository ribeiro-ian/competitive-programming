/*
    Beecrowd 1518 - Tartarugas
    https://judge.beecrowd.com/pt/problems/view/1518
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int x, y;
char dir[3];
pair<int,int> turtle[3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (1){
        cin >> x >> y;
        
        if (!x) break;
        
        for (int i = 0; i < 3; i++)
            scanf("%i %i %c", &turtle[i].first, &turtle[i].second, &dir[i]);
    }

    return 0;
}
