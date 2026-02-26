#include <stdio.h>
#include <stdlib.h>

int main(){
    int t;
    char a[10001],b[10001];
    scanf("%d", &t);

    for(int i = 0; i<t; i++){
        scanf("%s", &a);
        scanf("%s", &b);
        count = 0;
        int tam_aux = strlen(a);
        int tam = 0;
        int auxa = 0, auxb = 0;
        
        while (tam_aux > tam) {
            while (a[auxa] != b[auxb]) {
                auxa++;
                if (a[auxa] == 'z') {
                    a[auxa] = 'a';
                }
                count++;
            }
            
            if (a[auxa] == b[auxb]) {
                auxb++;
            }
            tam++;
        }
        
        printf("%d", count);
        
    }
    return 0;
}