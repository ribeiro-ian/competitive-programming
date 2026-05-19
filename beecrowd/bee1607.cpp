/*
 * Contest : Beecrowd
 * Problem : 1607 - Avance as Letras
 * Link    : https://judge.beecrowd.com/pt/problems/view/1607
 */

#include <stdio.h>

int main(){
  int n;
  scanf("%i", &n);
  
  for (int i = 0; i < n; i++){
    char str1[10001], str2[10001];
    scanf("%s %s", str1, str2);
    
    int contador = 0;
    for (int i = 0; str1[i] != '\0'; i++){
      if (str1[i] <= str2[i])
      contador += str2[i] - str1[i];
      else
      contador += 'z' - str1[i] + str2[i] - 'a' + 1;
    }
    
    printf("%i\n", contador);
  }
}