#include <bits/stdc++.h>
using namespace std;


int main(){
    int t1,t2;
    queue <char> copa;

    for (int i = 0; i < 16; i++)
        copa.push('A' + i);    
    
    for (int j = 8; j >= 1; j = j / 2){
        for (int i = 0; i < j; i++){
            cin >> t1 >> t2;

            if (t1 > t2){
                copa.push(copa.front());
                copa.pop();
            }
            else{
                copa.pop();
                copa.push(copa.front());
            }

            copa.pop();
        }
    }
    
    cout << copa.front() << endl;

    return 0;
}
