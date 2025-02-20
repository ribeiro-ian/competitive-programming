#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const map <char, double> id = {
    {'W', 1},
    {'H', 1.0/2},
    {'Q', 1.0/4},
    {'E', 1.0/8},
    {'S', 1.0/16},
    {'T', 1.0/32},
    {'X', 1.0/64},
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //  a duração de um compasso deve ser sempre 1.
    string str;

    while (1)
    {
        cin >> str;
        if (str == "*") break;

        float sum;
        int ans;
        sum = ans = 0;
        for (auto &c : str){
            if (c == '/'){
                if (sum == 1.0)
                    ans++;

                sum = 0;
                continue;
            }
            
            sum += id.at(c);
            // fprintf(stderr, "sum: %f\n", sum);
        }
                
        printf("%i\n", ans);
    }
    

    return 0;
}
