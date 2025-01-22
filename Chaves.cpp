#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    cin >> n;

    stack <char> s;
    string str;

    cin.ignore();

    for (int i = 0; i < n; i++){
        getline(cin, str);

        for (auto &c : str){
            if (c == '{'){
                s.push(c);
            }
            else if(c == '}'){
                if (s.empty()){
                    cout << "N\n";
                    return 0;
                }

                s.pop();
            }
        }
        cout << endl;
    }

    if (s.size())
        cout << "N\n";
    else
        cout << "S\n";

    return 0;
}
