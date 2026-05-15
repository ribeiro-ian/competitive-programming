/*
    Beecrowd 1467 - Zerinho ou Um
    https://judge.beecrowd.com/pt/problems/view/1467
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int a, b, c;

    while(cin >> a >> b >> c){
        int arr[] = {a,b,c};
        
        int cnt0 = count(arr, arr+3, 0);
        int cnt1 = count(arr, arr+3, 1);

        if(cnt0 == 0 || cnt1 == 0){
            printf("*\n");
            continue;
        }

        int aux = cnt0 < cnt1 ? 0 : 1;
        for(int i = 0; i < 3; i++){
            if(arr[i] == aux){
                printf("%c\n", 'A'+ i);
                break;
            }
        }

    }

    return 0;
}
