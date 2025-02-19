#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    map <string, int> tree;
    string str;

    int tc;
    cin >> tc;
    cin.ignore();
    getline(cin, str);
    
    while (tc--){
        double total = 0;
        tree.clear();

        while (getline(cin, str)){
            if (str.empty()) break;
            
            total++;
            
            tree[str] += 1;
        }
        
        for (auto t : tree){
            printf("%s %.4f\n", t.first.c_str(), 100*t.second/total);
        }

        if (tc != 0) printf("\n");
    }

    return 0;
}
