#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && a < c){
        printf("1\n");

        if (b < c)
            printf("2\n3");
        else
            printf("3\n2");
    }

    else if (b < a && b < c){
        printf("2\n");

        if (a < c)
            printf("1\n3");
        else
            printf("3\n1");
    }

    else if (c < a && c < b){
        printf("3\n");

        if (a < b)
            printf("1\n2");
        else
            printf("2\n1");
    }
    printf("\n");

    return 0;
}
