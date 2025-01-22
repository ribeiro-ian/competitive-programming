#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    cin.ignore();
    
    while(tc--){
        string str;

        getline(cin, str);

        for (auto &c : str){
            if (isalpha(c))
                c += 3;
        }
        
        reverse(str.begin(), str.end());

        for (size_t i = str.size()/2; i < str.size(); i++)
            str[i]--;        

        cout << str << endl;
    }

    return 0;
}
