#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    char d;

    while(1){
        cin >> d >> n;
        if (d == '0' && n == "0") break;

        string str = "";
        for (auto &c : n)
            if (d != c){
                if (str.empty() && c == '0')
                    continue; // pula para o proximo char da string
                
                str += c;
            }

        if (str.empty()) str += "0";
        
        printf("%s\n", str.c_str());
    }

    return 0;
}
