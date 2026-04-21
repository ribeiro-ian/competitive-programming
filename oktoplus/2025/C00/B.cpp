/*
    Beecrowd 1235 - De Dentro para Fora
    https://judge.beecrowd.com/pt/problems/view/1235
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    string str;

    cin >> tc;
    cin.ignore();

    while (tc--){
        getline(cin, str);

        for (int i = str.size()/2-1; i >= 0; i--)
            printf("%c", stri);
        
        for (int i = str.size()-1; i >= str.size()/2; i--)
            printf("%c", str[i]);
        
        printf("\n");
    }

    return 0;
}
