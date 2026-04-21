/*
    Beecrowd 2830 - Copa
    https://judge.beecrowd.com/pt/problems/view/2830
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int max = 16, kung, lu;
    queue <int> copa;

    cin >> kung >> lu;
    for (int i = 0; i < max; i++)
    {
        if (i+1 == kung || i+1 == lu)
        copa.push(1);
        else
        copa.push(0);
    }

    int cnt = 0;
    int t1, t2;
    while(t1 != t2 || t1 != 1){
        t1 = copa.front();
        copa.pop();
        t2 = copa.front();
        copa.pop();
        cnt++;

        copa.push(t1 || t2);
    }
    string ans;

    if (cnt <= 8)
        ans = "oitavas";
    else if(cnt <= 12)
        ans = "quartas";
    else if(cnt <= 14)
        ans = "semifinal";
    else
        ans = "final";

    printf("%s\n", ans.c_str());

    return 0;
}
