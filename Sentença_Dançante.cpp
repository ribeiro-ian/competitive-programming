#include <bits/stdc++.h>
using namespace std;

int main(){

    string str;

    while (getline(cin, str)){
        
        for (int i = 0, cnt = 0; i < str.length(); i++){
            if (!isalpha(str[i]))
                continue;

            if (cnt % 2 == 0)
                str[i] = toupper(str[i]);
            else
                str[i] = tolower(str[i]);
                
            cnt++; // cnt faz contagem dos caracteres da string, desconsiderando os espaços
        }

        cout << str << endl;
    }

    return 0;
}
