#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 12;
    printf("%i\n", n*n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i %i\n", i+1, j+1);
        }
        
    }
        

    return 0;
}
