#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc; cin >> tc;
    cin.ignore();

    string str;
    while(tc--){
        getline(cin, str);

        for (auto &c : str){
            if (isalpha(c) && c != ' ')
                c += 3;
        }

        reverse(str.begin(), str.end());

        for (int i = str.size()/2; i < str.size(); i++)
            str[i] -= 1;

        cout << str << endl;
    }

    return 0;
}
