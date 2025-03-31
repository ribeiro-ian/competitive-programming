/*
    Beecrowd 1367 - Ajude!
    https://judge.beecrowd.com/pt/problems/view/1367
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, pont, cnt, tempo;
    string str;
    char id;

    while (1)
    {
        cin >> n;

        if (n==0) break;

        pont = cnt = 0;

        vector <int> prob(26, 0);
        for(int i=0; i < n;i++){
            cin >> id >> tempo >> str;

            int idx = id - 'A';

            if (str == "correct"){
                if (prob[idx] > 0)
                    pont += tempo + 20*prob[idx];
                else
                    pont += tempo;

                cnt++;
            }
            else{
                prob[idx]++;
            }
        }

        printf("%i %i\n", cnt, pont);
    }
    

    return 0;
}
